#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    long long dp[1000001][2];
    long long solve(int idx, vector<int>& nums, bool flag) {
        if (idx >= n) return 0;
        if (dp[idx][flag] != -1) return dp[idx][flag];
        long long skip = solve(idx + 1, nums, flag);
        long long val = nums[idx];
        if (flag == false)
            val = -val;
        long long take = solve(idx + 1, nums, !flag) + val;
        return dp[idx][flag] = max(skip, take);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, true);
    }
};

int main() {
    int k;
    cin >> k;
    vector<int> nums(k);
    for (int i = 0; i < k; i++)
        cin >> nums[i];
    Solution obj;
    long long ans = obj.maxAlternatingSum(nums);
    cout << ans << endl;
    return 0;
}