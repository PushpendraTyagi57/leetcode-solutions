#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> segTree;
    void buildAndUpdateSegTree(int left, int right, int index, int queryIdx) {
        if (left == right) {
            segTree[index] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        if (queryIdx <= mid) {
            buildAndUpdateSegTree(left, mid, 2 * index + 1, queryIdx);
        }
        else {
            buildAndUpdateSegTree(mid + 1, right, 2 * index + 2, queryIdx);
        }
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    long long retrieveQuery(int left, int right, int index, int queryStart, int queryEnd) {
        if (right < queryStart || left > queryEnd) return 0;
        if (queryStart <= left && queryEnd >= right) return segTree[index];
        int mid = left + (right - left) / 2;
        long long leftCount = retrieveQuery(left, mid, 2 * index + 1, queryStart, queryEnd);
        long long rightCount = retrieveQuery(mid + 1, right, 2 * index + 2, queryStart, queryEnd);
        return leftCount + rightCount;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }
        segTree.resize(4 * n);
        buildAndUpdateSegTree(0, n - 1, 0, mp[nums1[0]]);
        long long result = 0;
        for (int i = 1; i < n; i++) {
            int idx = mp[nums1[i]];
            long long leftCommonCount = retrieveQuery(0, n - 1, 0, 0, idx);
            long long leftUncommonCount = i - leftCommonCount;
            long long elementsAfterIdx = n - idx - 1;
            long long rightCommonCount = elementsAfterIdx - leftUncommonCount;

            buildAndUpdateSegTree(0, n - 1, 0, idx);
            result += leftCommonCount * rightCommonCount;
        }
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    Solution obj;
    cout << obj.goodTriplets(nums1, nums2) << endl;
    return 0;
}