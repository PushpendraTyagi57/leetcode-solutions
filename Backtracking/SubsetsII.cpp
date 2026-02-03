class Solution {
public:
    void findSubsets(int idx, vector<int>& arr, set<vector<int>>& result, vector<int>& ds) {
        if (idx == arr.size()) {
            result.insert(ds);
            return;
        }
        ds.push_back(arr[idx]);
        findSubsets(idx + 1, arr, result, ds);
        ds.pop_back();
        findSubsets(idx + 1, arr, result, ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<int> ds;
        findSubsets(0, nums, result, ds);
        return vector<vector<int>>(result.begin(), result.end());
    }
};