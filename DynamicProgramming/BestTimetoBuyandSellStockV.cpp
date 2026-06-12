#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    const long long NEG = -1e18;
    vector<vector<vector<long long>>> dp;
    long long solve(int idx, int state, int k, vector<int>& prices) {
        if (idx == n || k == 0) {
            if (state == 0) return 0;
            return NEG;
        }
        if (dp[idx][state][k] != -1) return dp[idx][state][k];
        long long ans = 0;
        if (state == 0) {
            ans = max({
                -1LL * prices[idx] + solve(idx + 1, 1, k, prices),
                1LL * prices[idx] + solve(idx + 1, 2, k, prices),
                solve(idx + 1, 0, k, prices)
            });
        }
        else if (state == 1) {
            ans = max({
                1LL * prices[idx] + solve(idx + 1, 0, k - 1, prices),
                solve(idx + 1, 1, k, prices)
            });
        }
        else {
            ans = max({
                -1LL * prices[idx] + solve(idx + 1, 0, k - 1, prices),
                solve(idx + 1, 2, k, prices)
            });
        }
        return dp[idx][state][k] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.resize(1001, vector<vector<long long>>(3, vector<long long>(501, -1)));
        return solve(0, 0, k, prices);
    }
};

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    Solution obj;
    cout << obj.maximumProfit(prices, k) << endl;
    return 0;
}