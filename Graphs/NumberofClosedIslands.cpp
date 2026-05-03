#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    bool dfs(int row, int col, vector<vector<int>>& grid) {
        if (row >= m || row < 0 || col >= n || col < 0) return false;
        if (grid[row][col] == 1) return true;
        grid[row][col] = 1;
        bool leftClosed = dfs(row, col - 1, grid);
        bool rightClosed = dfs(row, col + 1, grid);
        bool upClosed = dfs(row - 1, col, grid);
        bool downClosed = dfs(row + 1, col, grid);
        return leftClosed && rightClosed && upClosed && downClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid)) count++;
                }
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
    cout << obj.closedIsland(grid) << endl;
    return 0;
}