#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfSets(int n, int K) {
        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }
        for (int k = 1; k <= K; k++) {
            vector<int> prevRowSum(n + 1, 0);
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % MOD;
            }
            for (int i = n - 1; i >= 0; i--) {
                int skip = dp[k][i + 1];
                int take = prevRowSum[i + 1];

                dp[k][i] = (take + skip) % MOD;
            }
        }

        return dp[K][0];
    }
};

int main () {
    int n, k;
    cin >> n >> k;
    Solution obj;
    cout << obj.numberOfSets(n, k) << endl;
    return 0;
}