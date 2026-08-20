#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = arr[0];
        dp[0][1] = 0;
        int maxSum = arr[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
            maxSum = max({maxSum, dp[i][0], dp[i][1]});
        }
        return maxSum;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.maximumSum(nums) << endl;
    return 0;
}