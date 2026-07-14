#include <bits/stdc++.h>

using namespace std;

int dp[201][201][201];
class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    int solve(int idx, int first, int second, vector<int>& nums) {
        if (idx >= n) {
            if (first != 0 && second != 0 && first == second) return 1;
            return 0;
        }
        if (dp[idx][first][second] != -1) return dp[idx][first][second];
        int skip = solve(idx + 1, first, second, nums);
        int take1 = solve(idx + 1, __gcd(first, nums[idx]), second, nums);
        int take2 = solve(idx + 1, first, __gcd(second, nums[idx]), nums);
        return dp[idx][first][second] = (0LL + skip + take1 + take2) % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};

int main() {
    int x; cin >> x;
    vector<int> nums(x);
    for (int i = 0; i < x; i++) {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.subsequencePairCount(nums) << endl;
    return 0;
}