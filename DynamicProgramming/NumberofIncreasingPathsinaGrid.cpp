#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp;

    bool isValid(int row, int col) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }

    int dfs(int row, int col, vector<vector<int>>& grid) {
        if (dp[row][col] != -1) return dp[row][col];
        int ans = 1;
        for (auto& dir : directions) {
            int new_i = row + dir[0];
            int new_j = col + dir[1];
            if (isValid(new_i, new_j) && grid[new_i][new_j] < grid[row][col])
                ans = (ans + dfs(new_i, new_j, grid)) % MOD;
        }
        return dp[row][col] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = (result + dfs(i, j, grid)) % MOD;
            }
        }

        return result;
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.countPaths(grid) << endl;
    return 0;
}