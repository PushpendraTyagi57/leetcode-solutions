#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));
        queue<pair<int, int>> pacificQueue, atlanticQueue;
        for (int i = 0; i < n; i++) {
            pacificVisited[0][i] = true;
            pacificQueue.push({0, i});
        }
        for (int i = 0; i < m; i++) {
            if (!pacificVisited[i][0]) {
                pacificVisited[i][0] = true;
                pacificQueue.push({i, 0});
            }
        }
        for (int i = 0; i < n; i++) {
            atlanticVisited[m - 1][i] = true;
            atlanticQueue.push({m - 1, i});
        }
        for (int i = 0; i < m; i++) {
            if (!atlanticVisited[i][n - 1]) {
                atlanticVisited[i][n - 1] = true;
                atlanticQueue.push({i, n - 1});
            }
        }
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pacificQueue.empty()) {
            int size = pacificQueue.size();
            while (size--) {
                int r = pacificQueue.front().first, c = pacificQueue.front().second;
                pacificQueue.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr >= 0 && nr < m && 
                        nc >= 0 && nc < n && 
                        !pacificVisited[nr][nc] && 
                        heights[nr][nc] >= heights[r][c]) 
                    {
                        pacificVisited[nr][nc] = true;
                        pacificQueue.push({nr, nc});
                    }
                }
            }
        }
        while (!atlanticQueue.empty()) {
            int size = atlanticQueue.size();
            while (size--) {
                int r = atlanticQueue.front().first, c = atlanticQueue.front().second;
                atlanticQueue.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        !atlanticVisited[nr][nc] &&
                        heights[nr][nc] >= heights[r][c])
                    {
                        atlanticVisited[nr][nc] = true;
                        atlanticQueue.push({nr, nc});
                    }
                }
            }
        }
        vector<vector<int>> answer;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) answer.push_back({i, j});
            }
        }
        return answer;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> heights(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> heights[i][j];
    Solution obj;
    vector<vector<int>> ans = obj.pacificAtlantic(heights);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            if (j == 1) {
                cout << ans[i][j];
                break;
            }
            cout << ans[i][j] << ", ";
        }
        if (i == ans.size() - 1) {
            cout << "]";
            break;
        }
        cout << "], ";
    }
    cout << "]";
    return 0;
}