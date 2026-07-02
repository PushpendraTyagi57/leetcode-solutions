#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        result[0][0] = grid[0][0];
        dq.push_front({0, 0});
        while (!dq.empty()) {
            int curr_i = dq.front().first;
            int curr_j = dq.front().second;
            dq.pop_front();
            for (auto& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
                if (result[new_i][new_j] > result[curr_i][curr_j] + grid[new_i][new_j]) {
                    result[new_i][new_j] = result[curr_i][curr_j] + grid[new_i][new_j];
                    if (grid[new_i][new_j] == 0) dq.push_front({new_i, new_j});
                    else dq.push_back({new_i, new_j});
                }

            }
        }
        int val = result[m - 1][n - 1];
        return health - val >= 1;
    }
};

int main() {
    int x, y, health;
    cin >> x >> y >> health;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << (obj.findSafeWalk(grid, health) ? "True" : "False") << endl;
    return 0;
}