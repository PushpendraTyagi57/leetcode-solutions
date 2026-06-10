#include <bits/stdc++.h>

using namespace std;

int dp[100001][2][3];

class Solution {
public:
    int n;
    int solve(int idx, int buyNow, int count, vector<int>& prices) {
        if (idx == n || count == 2) return 0;
        if (dp[idx][buyNow][count] != -1) return dp[idx][buyNow][count];
        int buyOrSkip = 0, sellOrSkip = 0;
        if (buyNow) {
            buyOrSkip = max(-prices[idx] + solve(idx + 1, 0, count, prices), solve(idx + 1, 1, count, prices));
        }
        else {
            sellOrSkip = max(prices[idx] + solve(idx + 1, 1, count + 1, prices), solve(idx + 1, 0, count, prices));
        }
        return dp[idx][buyNow][count] = max(buyOrSkip, sellOrSkip);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int count = 0, buyNow = 1;
        memset(dp, -1, sizeof(dp));
        return solve(0, buyNow, count, prices);
    }
};

int main() {
    int m; cin >> m;
    vector<int> prices(m);
    for (int i = 0; i < m; i++) cin >> prices[i];
    Solution obj;
    cout << obj.maxProfit(prices) << endl;
    return 0;
}