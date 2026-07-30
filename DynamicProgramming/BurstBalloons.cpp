#include <bits/stdc++.h>

using namespace std;

class Solution {
int dp[301][301];
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for (int idx = i; idx <= j; idx++) {
            int coins = (nums[idx] * nums[i - 1] * nums[j + 1]) + solve(i, idx - 1, nums) + solve(idx + 1, j, nums);
            ans = max(ans, coins); 
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        memset(dp, -1, sizeof(dp));
        return solve(1, nums.size() - 2, nums);
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.maxCoins(nums) << endl;
    return 0;
}