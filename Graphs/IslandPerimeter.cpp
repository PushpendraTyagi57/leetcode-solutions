#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    int perimeter;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isWater(int row, int col, vector<vector<int>>& grid) {
        return (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0);
    }
    void bfs(int row, int col, vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        que.push({row, col});
        grid[row][col] = -1;
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            int i = curr.first;
            int j = curr.second;
            for (auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (isWater(new_i, new_j, grid)) perimeter++;
                else if (grid[new_i][new_j] == 1) {
                    grid[new_i][new_j] = -1;
                    que.push({new_i, new_j});
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    bfs(i, j, grid);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};

int main () {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.islandPerimeter(grid) << endl;
    return 0;
}