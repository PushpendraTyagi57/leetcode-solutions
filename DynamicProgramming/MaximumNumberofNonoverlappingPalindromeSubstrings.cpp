#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> dp;
    vector<int> dpForSolve;
    int solve(string& s, int n, int& k) {
        if (n < k) return 0;
        if (dpForSolve[n] != -1) return dpForSolve[n];
        int result = solve(s, n - 1, k);
        int j = n - 1;
        for (int i = 0; j - i + 1 >= k; i++) {
            if (dp[i][j]) {
                result = max(result, 1 + solve(s, i, k));
            }
        }
        return dpForSolve[n] = result;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        dp.assign(n + 1, vector<bool>(n + 1, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (i == j) dp[i][j] = true;
                else if (i + 1 == j) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }
        dpForSolve.assign(n + 1, -1);
        return solve(s, n, k);
    }
};

int main () {
    string s;
    int k;
    cin >> s >> k;
    Solution obj;
    cout << obj.maxPalindromes(s, k) << endl;
    return 0;
}