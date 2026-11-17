#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(int row, int col, int k, vector<vector<int>> &piles)
    {
        if (k == 0)
            return 0;
        if (row >= m)
            return -1e9;
        if (col >= piles[row].size())
            return solve(row + 1, 0, k, piles);

        if (dp[row][col][k] != INT_MIN)
            return dp[row][col][k];

        int skip = solve(row + 1, 0, k, piles);
        int take = piles[row][col] + max(solve(row, col + 1, k - 1, piles), solve(row + 1, 0, k - 1, piles));
        return dp[row][col][k] = max(take, skip);
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        m = piles.size();
        n = piles[0].size();

        dp.resize(m);
        for (int i = 0; i < m; i++)
        {
            dp[i].assign(piles[i].size(), vector<int>(k + 1, INT_MIN));
        }
        return solve(0, 0, k, piles);
    }
};

int main()
{
    int x;
    cin >> x;
    vector<vector<int>> piles(x);
    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        piles[i].resize(y);
        for (int j = 0; j < y; j++)
        {
            cin >> piles[i][j];
        }
    }

    int k;
    cin >> k;
    Solution *obj = new Solution();
    cout << obj->maxValueOfCoins(piles, k) << "\n";
    return 0;
}