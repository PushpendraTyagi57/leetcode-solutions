#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int amount;
    cin >> amount;
    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}