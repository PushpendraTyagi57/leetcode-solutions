#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;
        if (i == m - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != INT_MIN) return dp[i][j1][j2];
        int ans = -1e9;
        for (int new_j1 = -1; new_j1 <= 1; new_j1++) {
            for (int new_j2 = -1; new_j2 <= 1; new_j2++) {
                if (j1 == j2) ans = max(ans, grid[i][j1] + solve(i + 1, j1 + new_j1, j2 + new_j2, grid));
                else ans = max(ans, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + new_j1, j2 + new_j2, grid));
            }
        }
        return dp[i][j1][j2] = ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return solve(0, 0, n - 1, grid);
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.cherryPickup(grid) << endl;
    return 0;
}