#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    void dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) return;
        grid[row][col] = 0;
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int row = 0; row < m; row++) {
            if (grid[row][0] == 1) dfs(row, 0, grid);
            if (grid[row][n - 1] == 1) dfs(row, n - 1, grid);
        }
        for (int col = 0; col < n; col++) {
            if (grid[0][col] == 1) dfs(0, col, grid);
            if (grid[m - 1][col] == 1) dfs(m - 1, col, grid);
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> grid[i][j];
    Solution obj;
    cout << obj.numEnclaves(grid) << endl;
    return 0;
}