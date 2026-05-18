#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int minCount = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + solve(n - i * i);
            minCount = min(minCount, result);
        }
        return dp[n] = minCount;
    }
    int numSquares(int n) {
        if (n <= 2) return n;
        dp.resize(n + 1, -1);
        return solve(n);
    }
};

int main() {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.numSquares(n) << endl;
    return 0;
}