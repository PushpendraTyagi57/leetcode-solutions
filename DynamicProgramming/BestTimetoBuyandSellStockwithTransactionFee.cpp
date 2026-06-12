#include <bits/stdc++.h>

using namespace std;

int dp[500001][2];
class Solution {
public:
    const int NEG = -1e9;
    int n;
    int solve(int idx, int buyNow, vector<int>& prices, int fee) {
        if (idx == n) {
            if (buyNow == 1) return 0;
            return NEG;
        }
        if (dp[idx][buyNow] != -1) return dp[idx][buyNow];
        int ans = 0;
        if (buyNow) {
            ans = max(-prices[idx] - fee + solve(idx + 1, 0, prices, fee), solve(idx + 1, 1, prices, fee));
        }
        else {
            ans = max(prices[idx] + solve(idx + 1, 1, prices, fee), solve(idx + 1, 0, prices, fee));
        }
        return dp[idx][buyNow] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        int buyNow = 1;
        return solve(0, buyNow, prices, fee);
    }
};

int main() {
    int n; cin >> n;
    int fee; cin >> fee;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    Solution obj;
    cout << obj.maxProfit(prices, fee) << endl;
    return 0;
}