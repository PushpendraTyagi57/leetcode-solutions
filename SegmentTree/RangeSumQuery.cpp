#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    int n;
    vector<int> segTree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);
        buildTree(0, n - 1, 0, nums);
    }

    void buildTree(int l, int r, int idx, vector<int>& nums) {
        if (l == r) {
            segTree[idx] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(l, mid, 2 * idx + 1, nums);
        buildTree(mid + 1, r, 2 * idx + 2, nums);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    void updateTree(int left, int right, int currIdx, int index, int val) {
        if (left == right) {
            segTree[currIdx] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (index <= mid) updateTree(left, mid, 2 * currIdx + 1, index, val);
        else updateTree(mid + 1, right, 2 * currIdx + 2, index, val);
        segTree[currIdx] = segTree[2 * currIdx + 1] + segTree[2 * currIdx + 2];
    }

    int sumQuery(int left, int right, int index, int start, int end) {
        if (end < left || start > right) return 0;
        if (left >= start && right <= end) return segTree[index];
        int mid = left + (right - left) / 2;
        return sumQuery(left, mid, 2 * index + 1, start, end)
                + sumQuery(mid + 1, right, 2 * index + 2, start, end);
    }
    
    void update(int index, int val) {
        updateTree(0, n - 1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumQuery(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */