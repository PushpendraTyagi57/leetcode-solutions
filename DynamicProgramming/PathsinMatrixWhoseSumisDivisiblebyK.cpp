#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(int row, int col, int currSum, vector<vector<int>>& grid, int& k) {
        if (row >= m || col >= n) return 0;
        if (row == m - 1 && col == n - 1) {
            currSum += grid[row][col];
            if (currSum % k == 0) return 1;
            return 0;
        }
        if (dp[row][col][currSum] != -1) return dp[row][col][currSum];
        int down = solve(row + 1, col, (currSum + grid[row][col]) % k, grid, k);
        int right = solve(row, col + 1, (currSum + grid[row][col]) % k, grid, k);
        return dp[row][col][currSum] = (down + right) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, 0, grid, k);
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
    int k; cin >> k;
    Solution obj;
    cout << obj.numberOfPaths(grid, k) << endl;
    return 0;
}