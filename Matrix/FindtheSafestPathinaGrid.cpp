#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool solve(vector<vector<int>>& distToThief, int mid) {
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if (distToThief[0][0] < mid) return false;
        que.push({0, 0});
        visited[0][0] = true;
        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();
            if (curr_i == n - 1 && curr_j == n - 1) return true;
            for (auto& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                    if (distToThief[new_i][new_j] < mid) continue;
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> distToThief(n, vector<int>(n, -1));
        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();
                distToThief[curr_i][curr_j] = level;
                for (auto &dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j])
                        continue;
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
            level++;
        }

        int low = 0, high = 400;
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(distToThief, mid)) {
                result = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return result;
    }
};

int main() {
    int m; cin >> m;
    vector<vector<int>> grid(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.maximumSafenessFactor(grid) << endl;
    return 0;
}