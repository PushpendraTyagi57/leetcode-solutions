#include <bits/stdc++.h>

using namespace std;

int dp[100001][3][3];
class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int idx, int countA, int consecutiveL, int& n) {
        if (idx < 0) return 1;
        if (dp[idx][countA][consecutiveL] != -1) return dp[idx][countA][consecutiveL];
        int takeA = 0;
        if (countA == 0) {
            takeA += solve(idx - 1, countA + 1, 0, n);
        }
        int takeL = 0;
        if (consecutiveL <= 1) {
            takeL += solve(idx - 1, countA, consecutiveL + 1, n);
        }
        int takeP = solve(idx - 1, countA, 0, n);
        return dp[idx][countA][consecutiveL] = (0LL + takeA + takeL + takeP) % MOD;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n - 1, 0, 0, n);
    }
};

int main () {
    int n; cin >> n;
    Solution obj;
    cout << obj.checkRecord(n) << endl;
    return 0;
}