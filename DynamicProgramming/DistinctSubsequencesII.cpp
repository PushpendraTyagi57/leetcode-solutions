#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[2001];
    vector<int> prev;
    int solve(int i) {
        if (i == 0) return 1;
        if (dp[i] != -1) return dp[i];
        int total = (2 * solve(i - 1)) % MOD;
        if (prev[i] != 0) {
            int duplicates = solve(prev[i] - 1);
            total = (total - duplicates + MOD) % MOD;
        }
        return dp[i] = total;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        prev.assign(n + 1, 0);
        vector<int> lastSeen(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n) - 1 + MOD) % MOD;
    }
};

int main () {
    string s; cin >> s;
    Solution obj;
    cout << obj.distinctSubseqII(s) << endl;
    return 0;
}