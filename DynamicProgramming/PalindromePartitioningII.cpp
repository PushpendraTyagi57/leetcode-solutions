#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (i == j) dp[i][j] = true;
                else if (i + 1 == j) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }
        vector<int> cuts(n);
        for (int i = 0; i < n; i++) {
            if (dp[0][i]) cuts[i] = 0;
            else {
                cuts[i] = INT_MAX;
                for (int k = 0; k < i; k++) {
                    if (dp[k + 1][i] && 1 + cuts[k] < cuts[i]) {
                        cuts[i] = 1 + cuts[k];
                    }
                }
            }
        }
        return cuts[n - 1];
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minCut(s) << endl;
    return 0;
}