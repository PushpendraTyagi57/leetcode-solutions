#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(int i, int j, string& s, string& t) {
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return dp[i][j] = solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
        return dp[i][j] = solve(i - 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        dp.assign(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, t);
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution solution;
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}