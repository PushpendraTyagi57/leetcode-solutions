#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (idx >= n || target < 0) return 0;
        if (dp[idx][target] != -1) return dp[idx][target];
        int take = solve(0, nums, target - nums[idx]);
        int skip = solve(idx + 1, nums, target);
        return dp[idx][target] = take + skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(n, vector<int>(target + 1, -1));
        return solve(0, nums, target);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    int target;
    cin >> target;
    cout << obj.combinationSum4(nums, target) << endl;
    return 0;
}