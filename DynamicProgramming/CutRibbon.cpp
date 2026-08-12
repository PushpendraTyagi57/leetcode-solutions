#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int n, int& a, int& b, int& c) {
        if (n < 0) return -1e9;
        if (n == 0) return 0;
        if (dp[n] != INT_MIN) return dp[n];
        int cutA = 1 + solve(n - a, a, b, c);
        int cutB = 1 + solve(n - b, a, b, c);
        int cutC = 1 + solve(n - c, a, b, c);
        return dp[n] = max({cutA, cutB, cutC});
    }
    int cutRibbon(int n, int& a, int& b, int& c) {
        dp.assign(n + 1, INT_MIN);
        return solve(n, a, b, c);
    }
};

int main () {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    Solution obj;
    cout << obj.cutRibbon(n, a, b, c);
    return 0;
}