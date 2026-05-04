#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    queue<pair<int, int>> que;
    void dfs(int row, int col, vector<vector<int>>& grid) {
        if (grid[row][col] != 1) return;
        grid[row][col] = 2;
        que.push({row, col});
        if (row - 1 >= 0) dfs(row - 1, col, grid);
        if (row + 1 < n) dfs(row + 1, col, grid);
        if (col - 1 >= 0) dfs(row, col - 1, grid);
        if (col + 1 < n) dfs(row, col + 1, grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true;
                }
            }
        }
        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<int, int> P = que.front();
                que.pop();
                int row = P.first, col = P.second;
                int dr[4] = {1, -1, 0, 0};
                int dc[4] = {0, 0, 1, -1};
                for (int k = 0; k < 4; k++) {
                    int newRow = row + dr[k];
                    int newCol = col + dc[k];
                    if (newRow < n && newRow >= 0 && newCol < n && newCol >= 0) {
                        if (grid[newRow][newCol] == 1) return steps;
                        if (grid[newRow][newCol] == 0) {
                            grid[newRow][newCol] = 2;
                            que.push({newRow, newCol});
                        }
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    int x;
    cin >> x;
    vector<vector<int>> grid(x, vector<int>(x));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            cin >> grid[i][j];
    Solution obj;
    cout << obj.shortestBridge(grid) << endl;
    return 0;
}