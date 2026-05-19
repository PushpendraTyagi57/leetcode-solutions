#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        int result = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    que.push({i, j});
                    int currIsland = 1;
                    while (!que.empty()) {
                        int size = que.size();
                        while (size--) {
                            int row = que.front().first;
                            int col = que.front().second;
                            que.pop();
                            if (row + 1 < m && grid[row + 1][col] == 1 && !visited[row + 1][col]) {
                                que.push({row + 1, col});
                                visited[row + 1][col] = true;
                                currIsland++;
                            }
                            if (row - 1 >= 0 && grid[row - 1][col] == 1 && !visited[row - 1][col]) {
                                que.push({row - 1, col});
                                visited[row - 1][col] = true;
                                currIsland++;
                            }
                            if (col + 1 < n && grid[row][col + 1] == 1 && !visited[row][col + 1]) {
                                que.push({row, col + 1});
                                visited[row][col + 1] = true;
                                currIsland++;
                            }
                            if (col - 1 >= 0 && grid[row][col - 1] == 1 && !visited[row][col - 1]) {
                                que.push({row, col - 1});
                                visited[row][col - 1] = true;
                                currIsland++;
                            }
                        }
                    }
                    result = max(result, currIsland);
                }
            }
        }
        return (result == INT_MIN) ? 0 : result;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.maxAreaOfIsland(grid) << endl;
    return 0;
}