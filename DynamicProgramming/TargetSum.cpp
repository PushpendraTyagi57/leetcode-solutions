#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    int S;
    vector<vector<int>> dp;
    int solve(int i, int currSum, vector<int>& nums, int target) {
        if (i == n) {
            if (currSum == target) return 1;
            else return 0;
        }
        if (dp[i][currSum + S] != -1) return dp[i][currSum + S];
        int plus = solve(i + 1, currSum + nums[i], nums, target);
        int minus = solve(i + 1, currSum - nums[i], nums, target);
        return dp[i][currSum + S] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        S = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(n + 1, vector<int>(2 * S + 1, -1));
        return solve(0, 0, nums, target);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int target;
    cin >> target;
    Solution obj;
    cout << obj.findTargetSumWays(nums, target) << endl;
    return 0;
}