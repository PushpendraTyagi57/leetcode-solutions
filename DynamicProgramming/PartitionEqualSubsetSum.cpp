#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
        for (int i = 0; i < n + 1; i++) dp[i][0] = true;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum / 2 + 1; j++) {
                bool skip = dp[i - 1][j];
                bool take = false;
                if (nums[i - 1] <= j) take = dp[i - 1][j - nums[i - 1]];
                dp[i][j] = take || skip;
            }
        }
        return dp[n][sum / 2];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    bool ans = obj.canPartition(nums);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}