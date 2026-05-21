#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        int result = INT_MIN;
        for (int i = 1; i <= n - 1; i++) {
            int prod = i * max(n - i, solve(n - i));
            result = max(result, prod);
        }
        return dp[n] = result;
    }
    int integerBreak(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};

int main() {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.integerBreak(n) << endl;
    return 0;
}