#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n - 1; i++) {
            int skip = dp[i - 1];
            int steal = nums[i - 1] + ((i - 2 >= 0) ? dp[i - 2] : 0);
            dp[i] = max(skip, steal);
        }
        int result1 = dp[n - 1];
        dp.clear();
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int skip = dp[i - 1];
            int steal = nums[i - 1] + ((i - 2 >= 0) ? dp[i - 2] : 0);
            dp[i] = max(skip, steal);
        }
        int result2 = dp[n];
        return max(result1, result2);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.rob(nums) << endl;
    return 0;
}