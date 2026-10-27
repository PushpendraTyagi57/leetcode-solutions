#include <bits/stdc++.h>

using namespace std;

int dp[1001][2];
class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int idx, bool possible, int& n) {
        if (idx == n) return !possible;
        if (idx >= n) return 0;
        if (dp[idx][possible] != -1) return dp[idx][possible];
        if (possible) {
            return (solve(idx + 1, false, n) + solve(idx + 1, true, n)) % MOD;
        }
        return dp[idx][possible] = (solve(idx + 1, false, n) + solve(idx + 2, false, n) + (2LL * solve(idx + 2, true, n))) % MOD;
    }
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, false, n);
    }
};

int main() {
    int n;
    cin >> n;
    Solution* obj = new Solution();
    cout << obj->numTilings(n) << "\n";
    return 0;
}