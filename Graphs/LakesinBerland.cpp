#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    void dfs(int row, int col, int m, int n, vector<vector<bool>>& visited, vector<vector<char>>& grid, vector<pair<int, int>>& lake) {
        visited[row][col] = true;
        lake.push_back({row, col});
        for (auto& dir : directions) {
            int new_i = row + dir[0];
            int new_j = col + dir[1];
            if (isValid(new_i, new_j, m, n) && grid[new_i][new_j] == '.' && !visited[new_i][new_j]) dfs(new_i, new_j, m, n, visited, grid, lake);
        }
    }
    pair<int, vector<vector<char>>> captureRegions(int k, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, vector<pair<int, int>>>> lakes;
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == '.' && !visited[0][i]) {
                vector<pair<int, int>> lake;
                dfs(0, i, m, n, visited, grid, lake);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[m - 1][i] == '.' && !visited[m - 1][i]) {
                vector<pair<int, int>> lake;
                dfs(m - 1, i, m, n, visited, grid, lake);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == '.' && !visited[i][0]) {
                vector<pair<int, int>> lake;
                dfs(i, 0, m, n, visited, grid, lake);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == '.' && !visited[i][n - 1]) {
                vector<pair<int, int>> lake;
                dfs(i, n - 1, m, n, visited, grid, lake);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.' && !visited[i][j]) {
                    vector<pair<int, int>> lake;
                    dfs(i, j, m, n, visited, grid, lake);
                    lakes.push_back({lake.size(), lake});
                }
            }
        }

        sort(lakes.begin(), lakes.end());
        int remove = lakes.size() - k;
        int cellsFilled = 0;

        for (int i = 0; i < remove; i++) {
            for (auto& cell : lakes[i].second) {
                grid[cell.first][cell.second] = '*';
                cellsFilled++;
            }
        }
        
        return {cellsFilled, grid};
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    auto ans = obj.captureRegions(k, grid);
    cout << ans.first << "\n";
    for (auto& row : ans.second) {
        for (char ch : row) cout << ch;
        cout << "\n";
    }
    return 0;
}