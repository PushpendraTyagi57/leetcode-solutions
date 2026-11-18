#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int m;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int idx, int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        if (idx >= m && minProfit <= 0)
            return 1;
        if (idx >= m && minProfit > 0)
            return 0;

        if (dp[idx][n][minProfit] != -1)
            return dp[idx][n][minProfit];
        int skipCrime = solve(idx + 1, n, minProfit, group, profit);
        int doCrime = 0;
        if (group[idx] <= n)
        {
            doCrime = solve(idx + 1, n - group[idx], max(0, minProfit - profit[idx]), group, profit);
        }
        return dp[idx][n][minProfit] = (skipCrime + doCrime) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        m = group.size();

        dp.assign(m, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return solve(0, n, minProfit, group, profit);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, minProfit;
    cin >> n >> minProfit;
    int x;
    cin >> x;
    vector<int> group(x);
    for (int i = 0; i < x; i++)
    {
        cin >> group[i];
    }

    vector<int> profit(x);
    for (int i = 0; i < x; i++)
    {
        cin >> profit[i];
    }

    Solution *obj = new Solution();
    cout << obj->profitableSchemes(n, minProfit, group, profit) << "\n";
    return 0;
}