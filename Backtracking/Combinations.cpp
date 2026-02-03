class Solution {
public:
    void findCombinations(int start, int n, int k, vector<vector<int>>& result, vector<int>& ds) {
        if (ds.size() == k) {
            result.push_back(ds);
            return;
        }
        for (int i = start; i <= n; i++) {
            ds.push_back(i);
            findCombinations(i + 1, n, k, result, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> ds;
        findCombinations(1, n, k, result, ds);
        return result;
    }
};