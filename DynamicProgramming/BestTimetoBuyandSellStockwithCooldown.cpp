#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, int buyNow, vector<int>& prices) {
        if (idx >= n) return 0;
        if (dp[idx][buyNow] != -1) return dp[idx][buyNow];
        int buy = 0, sell = 0;
        if (buyNow) {
            buy = max(-prices[idx] + solve(idx + 1, 0, prices), solve(idx + 1, 1, prices));
        }
        else {
            sell = max(prices[idx] + solve(idx + 2, 1, prices), solve(idx + 1, 0, prices));
        }
        return dp[idx][buyNow] = max(buy, sell);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int buyNow = 1;
        dp.resize(n, vector<int>(2, -1));
        return solve(0, buyNow, prices);
    }
};

int main() {
    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    Solution obj;
    cout << obj.maxProfit(prices) << endl;
    return 0;
}