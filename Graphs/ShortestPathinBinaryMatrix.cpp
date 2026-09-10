#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;

        vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<pair<int, int>> que;
        int level = 1;
        que.push({0, 0});
        visited[0][0] = true;

        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                auto curr = que.front();
                int row = curr.first;
                int col = curr.second;
                que.pop();
                if (row == m - 1 && col == n - 1) return level;
                for (auto& dir : directions) {
                    int new_i = row + dir[0];
                    int new_j = col + dir[1];
                    if (isValid(new_i, new_j, grid) && !visited[new_i][new_j] && grid[new_i][new_j] == 0) {
                        visited[new_i][new_j] = true;
                        que.push({new_i, new_j});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}