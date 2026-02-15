class Solution {
public:
    int t[101];
    int solve(int idx, int n, vector<int>& nums) {
        if (idx >= n)
            return 0;
        if (t[idx] != -1)
            return t[idx];
        int steal = nums[idx] + solve(idx + 2, n, nums);
        int skip = solve(idx + 1, n, nums);
        return t[idx] = max(steal, skip);
        }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        return solve(0, n, nums);
    }
};