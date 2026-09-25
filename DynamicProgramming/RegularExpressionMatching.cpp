#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    bool solve(int i, int j, string s, string p) {
        if (j >= n) {
            return i >= m;
        }
        if (dp[i][j] != -1) return dp[i][j];
        bool firstMatch = false;
        if (i < m && (p[j] == s[i] || p[j] == '.')) {
            firstMatch = true;
        }

        if (p[j + 1] == '*') {
            bool take = firstMatch && solve(i + 1, j, s, p);
            bool notTake = solve(i, j + 2, s, p);

            return dp[i][j] = take || notTake;
        }

        return dp[i][j] = firstMatch && solve(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, s, p);
    }
};

int main () {
    string s, p;
    cin >> s >> p;
    Solution obj;
    cout << (obj.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}