class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                sum += nums[i];
        }
        vector<int> result;
        for (auto &query : queries) {
            if (nums[query[1]] % 2 == 0)
                sum -= nums[query[1]];
            nums[query[1]] += query[0];
            if (nums[query[1]] % 2 == 0)
                sum += nums[query[1]];
            result.push_back(sum);
        }
        return result;
    }
};