#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
public:
    int m;
    vector<int> segTree;
    SegmentTree(int size) {
        m = size;
        segTree.assign(4 * m, 0);
    }

    void segmentTreeUpdateQuery(int index, int rootStart, int rootEnd, int compressedValue) {
        if (rootStart == rootEnd) {
            segTree[index]++;
            return;
        }
        int mid = rootStart + (rootEnd - rootStart) / 2;
        if (compressedValue <= mid) segmentTreeUpdateQuery(2 * index + 1, rootStart, mid, compressedValue);
        else segmentTreeUpdateQuery(2 * index + 2, mid + 1, rootEnd, compressedValue);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    void update(int compressedValue) {
        segmentTreeUpdateQuery(0, 0, m - 1, compressedValue);
    }

    int segmentTreeRangeSumQuery(int rootStart, int rootEnd, int index, int queryStart, int queryEnd) {
        if (queryEnd < rootStart || queryStart > rootEnd) return 0;
        if (queryStart <= rootStart && queryEnd >= rootEnd) return segTree[index];
        int mid = rootStart + (rootEnd - rootStart) / 2;
        return segmentTreeRangeSumQuery(rootStart, mid, 2 * index + 1, queryStart, queryEnd) +
                segmentTreeRangeSumQuery(mid + 1, rootEnd, 2 * index + 2, queryStart, queryEnd);
    }

    int query(int queryStart, int queryEnd) {
        return segmentTreeRangeSumQuery(0, m - 1, 0, queryStart, queryEnd);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        unordered_map<int, int> mp;
        int compressedValue = 0;
        for (int& num : sortedNums) {
            if (!mp.count(num)) {
                mp[num] = compressedValue;
                compressedValue++;
            }
        }

        int m = mp.size();

        vector<int> arr1;
        vector<int> arr2;

        SegmentTree segTree1(m);
        SegmentTree segTree2(m);

        arr1.push_back(nums[0]);
        segTree1.update(mp[nums[0]]);

        arr2.push_back(nums[1]);
        segTree2.update(mp[nums[1]]);
        for (int i = 2; i < nums.size(); i++) {
            int compressedValue = mp[nums[i]];
            int count1 = segTree1.query(compressedValue + 1, m - 1);
            int count2 = segTree2.query(compressedValue + 1, m - 1);

            bool addToArr1 = false;
            if (count1 > count2) {
                addToArr1 = true;
            }
            else if (count2 > count1) {
                addToArr1 = false;
            }
            else {
                addToArr1 = (arr1.size() <= arr2.size());
            }

            if (addToArr1) {
                arr1.push_back(nums[i]);
                segTree1.update(compressedValue);
            }
            else {
                arr2.push_back(nums[i]);
                segTree2.update(compressedValue);
            }
        }

        for (int& num : arr2) arr1.push_back(num);
        return arr1;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.resultArray(nums);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}