#include <bits/stdc++.h>

using namespace std;

int dp[22][22];
class Solution {
    public:
    int totalSum;
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        if (i == j) return nums[i];
        if (dp[i][j] != -1) return dp[i][j];
        int take_i = nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int take_j = nums[j] + min(solve(i, j - 2, nums), solve(i + 1, j - 1, nums));
        return dp[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for (int& num : nums) totalSum += num;
        memset(dp, -1, sizeof(dp));
        int playerOneScore = solve(0, n - 1, nums);
        int playerTwoScore = totalSum - playerOneScore;
        return playerOneScore >= playerTwoScore;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    bool ans = obj.predictTheWinner(nums);
    cout << ((ans == 1) ? "true" : "false") << endl;
    return 0;
}