#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<int> dp;
    int solve(int i, string& pressedKeys) {
        if (i >= n) return 1;
        if (dp[i] != -1) return dp[i];
        int ans = 0;
        int limit = (pressedKeys[i] == '7' || pressedKeys[i] == '9') ? 4 : 3;
        for (int len = 1; len <= limit; len++) {
            if (i + len - 1 >= n) break;
            if (pressedKeys[i] != pressedKeys[i + len - 1]) break;
            ans = (ans + solve(i + len, pressedKeys)) % MOD;
        }
        return dp[i] = ans % MOD;
    }
    int countTexts(string pressedKeys) {
        n = pressedKeys.size();
        dp.assign(n, -1);
        return solve(0, pressedKeys);
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.countTexts(s) << endl;
    return 0;
}