#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> segMin;
    vector<int> segMax;
    vector<int> lazy;
    int n;

    void propagate(int index, int rootStart, int rootEnd) {
        if (lazy[index] != 0) {
            segMin[index] += lazy[index];
            segMax[index] += lazy[index];

            if (rootStart != rootEnd) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }
    }

    void segmentTreeRangeUpdateQuery(int rootStart, int rootEnd, int index, int queryStart, int queryEnd, int val) {
        propagate(index, rootStart, rootEnd);

        if (rootEnd < queryStart || rootStart > queryEnd) return;

        if (queryStart <= rootStart && queryEnd >= rootEnd) {
            lazy[index] += val;
            propagate(index, rootStart, rootEnd);
            return;
        }

        int mid = rootStart + (rootEnd - rootStart) / 2;

        segmentTreeRangeUpdateQuery(rootStart, mid, 2 * index + 1, queryStart, queryEnd, val);
        segmentTreeRangeUpdateQuery(mid + 1, rootEnd, 2 * index + 2, queryStart, queryEnd, val);

        segMin[index] = min(segMin[2 * index + 1], segMin[2 * index + 2]);
        segMax[index] = max(segMax[2 * index + 1], segMax[2 * index + 2]);
    }

    int findLeftMostZero(int index, int rootStart, int rootEnd) {
        propagate(index, rootStart, rootEnd);

        if (segMin[index] > 0 || segMax[index] < 0) return -1;
        if (rootStart == rootEnd) return rootStart;

        int mid = rootStart + (rootEnd - rootStart) / 2;
        int leftResult = findLeftMostZero(2 * index + 1, rootStart, mid);

        if (leftResult != -1) {
            return leftResult;
        }

        return findLeftMostZero(2 * index + 2, mid + 1, rootEnd);
    }
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        segMin.assign(4 * n, 0);
        segMax.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        int longestSubarray = 0;
        vector<int> cumulativeSum(n, 0);
        unordered_map<int, int> mp;

        for (int r = 0; r < n; r++) {
            int val = nums[r] % 2 == 0 ? 1 : -1;
            int prev = -1;
            if (mp.count(nums[r])) {
                prev = mp[nums[r]];
            }
            if (prev != -1) {
                segmentTreeRangeUpdateQuery(0, n - 1, 0, 0, prev, -val);
            }

            segmentTreeRangeUpdateQuery(0, n - 1, 0, 0, r, val);

            int l = findLeftMostZero(0, 0, n - 1);
            if (l != -1) {
                longestSubarray = max(longestSubarray, r - l + 1);
            }
            mp[nums[r]] = r;
        }
        return longestSubarray;
    }
};

int main () {
    int m; cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.longestBalanced(nums) << endl;
    return 0;
}