#include <bits/stdc++.h>

using namespace std;

int dp[101][101][3][11];
const int MOD = 1e8;
class Solution {
public:
    // lastType = 1 -> horseMen, lastType = 0 -> footMen
    int solve(int usedFootmen, int usedHorsemen, int lastType, int consecutive, int& n1, int& n2, int& k1, int& k2) {
        if (usedFootmen == n1 && usedHorsemen == n2) return 1;
        if (dp[usedFootmen][usedHorsemen][lastType][consecutive] != -1) return dp[usedFootmen][usedHorsemen][lastType][consecutive];
        int ans = 0;
        if (lastType == 0) {
            if (usedFootmen < n1 && consecutive < k1) {
                ans += solve(usedFootmen + 1, usedHorsemen, 0, consecutive + 1, n1, n2, k1, k2);
            }
            if (usedHorsemen < n2) {
                ans += solve(usedFootmen, usedHorsemen + 1, 1, 1, n1, n2, k1, k2);
            }
        }
        else {
            if (usedHorsemen < n2 && consecutive < k2) {
                ans += solve(usedFootmen, usedHorsemen + 1, 1, consecutive + 1, n1, n2, k1, k2);
            }
            if (usedFootmen < n1) {
                ans += solve(usedFootmen + 1, usedHorsemen, 0, 1, n1, n2, k1, k2);
            }
        }
        return dp[usedFootmen][usedHorsemen][lastType][consecutive] = ans % MOD;
    }
    int caesarLegions(int n1, int n2, int k1, int k2) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        if (n1 > 0) ans += solve(1, 0, 0, 1, n1, n2, k1, k2);
        if (n2 > 0) ans += solve(0, 1, 1, 1, n1, n2, k1, k2);
        return ans % MOD;
    }
};

int main () {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    Solution obj;
    cout << obj.caesarLegions(n1, n2, k1, k2);
    return 0;
}