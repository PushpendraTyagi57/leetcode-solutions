#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N, M, K;
    const int MOD = 1e9 + 7;
    int dp[51][51][101];
    int solve(int idx, int searchCost, int maxVal) {
        if (idx >= N) {
            if (searchCost == K) return 1;
            return 0;
        }
        if (dp[idx][searchCost][maxVal] != -1) return dp[idx][searchCost][maxVal];
        int result = 0;
        for (int i = 1; i <= M; i++) {
            if (i > maxVal) result = (result + solve(idx + 1, searchCost + 1, i)) % MOD;
            else result = (result + solve(idx + 1, searchCost, maxVal)) % MOD;
        }
        return dp[idx][searchCost][maxVal] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Solution obj;
    cout << obj.numOfArrays(n, m, k) << endl;
    return 0;
}