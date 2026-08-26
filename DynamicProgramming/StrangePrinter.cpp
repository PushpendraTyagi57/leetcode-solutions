#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, string& s) {
        if (i == j) return 1;
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int k = i;
        while (k <= j && s[k] == s[i]) k++;
        int firstNonMatching = 1 + solve(k, j, s);
        int tryAfterFirstNonMatching = INT_MAX;
        for (int x = k + 1; x <= j; x++) {
            if (s[x] == s[i]) tryAfterFirstNonMatching = min(tryAfterFirstNonMatching, solve(k, x - 1, s) + solve(x, j, s));
        }
        return dp[i][j] = min(firstNonMatching, tryAfterFirstNonMatching);
    }
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, s);
    }
};

int main () {
    string s; cin >> s;
    Solution obj;
    cout << obj.strangePrinter(s) << endl;
    return 0;
}