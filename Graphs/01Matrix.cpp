#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!que.empty()) {
            auto curr = que.front();
            int row = curr.first;
            int col = curr.second;
            que.pop();
            for (auto& dir : directions) {
                int new_i = row + dir[0];
                int new_j = col + dir[1];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && result[new_i][new_j] == -1) {
                    result[new_i][new_j] = result[row][col] + 1;
                    que.push({new_i, new_j});
                }
            }
        }
        return result;
    }
};

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> answer = obj.updateMatrix(mat);
    cout << "[";
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                cout << answer[i][j];
                break;
            }
            cout << answer[i][j] << ",";
        }
        if (i == m - 1) {
            cout << "]";
            break;
        }
        cout << "],";
    }
    cout << "]";
    return 0;
}