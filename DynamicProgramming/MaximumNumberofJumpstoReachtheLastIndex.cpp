#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int idx = 1; idx < n; idx++) {
            for (int i = idx - 1; i >= 0; i--) {
                int diff = nums[i] - nums[idx];
                if (diff >= -target && diff <= target) {
                    if (dp[i] != INT_MIN) {
                        dp[idx] = max(dp[idx], 1 + dp[i]);
                    }
                }
            }
        }
        return (dp[n - 1] == INT_MIN ? -1 : dp[n - 1]);
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
    cout << obj.maximumJumps(nums, target) << endl;
    return 0; 
}