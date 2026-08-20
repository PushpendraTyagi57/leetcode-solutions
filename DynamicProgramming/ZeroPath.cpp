#include <bits/stdc++.h>

using namespace std;

int dp[1002][1002][402];
class Solution
{
public:
    bool solve(int row, int col, int sum, vector<vector<int>> &grid, int &m, int &n)
    {
        sum += grid[row][col];
        if (row == m - 1 && col == n - 1)
        {
            return (sum == 0);
        }
        int down = 0;
        if (row + 1 < m)
            down = solve(row + 1, col, sum, grid, m, n);
        int right = 0;
        if (col + 1 < n)
            right = solve(row, col + 1, sum, grid, m, n);
        return (down || right);
    }
    bool possiblePath(vector<vector<int>> &grid, int &m, int &n)
    {
        return solve(0, 0, 0, grid, m, n);
    }
};

int main()
{
    int t;
    cin >> t;
    Solution obj;
    for (int i = 0; i < t; i++)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        if (obj.possiblePath(grid, m, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}