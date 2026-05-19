#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        queue<pair<int, int>> que;
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    que.push({i, j});
                    visited[i][j] = true;
                    while (!que.empty()) {
                        int size = que.size();
                        while (size--) {
                            int row = que.front().first;
                            int col = que.front().second;
                            que.pop();
                            if (row + 1 < m && grid[row + 1][col] == '1' && !visited[row + 1][col]) {
                                que.push({row + 1, col});
                                visited[row + 1][col] = true;
                            }
                            if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col]) {
                                que.push({row - 1, col});
                                visited[row - 1][col] = true;
                            }
                            if (col + 1 < n && grid[row][col + 1] == '1' && !visited[row][col + 1]) {
                                que.push({row, col + 1});
                                visited[row][col + 1] = true;
                            }
                            if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1]) {
                                que.push({row, col - 1});
                                visited[row][col - 1] = true;
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    Solution obj;
    cout << obj.numIslands(grid) << endl;
    return 0;
}