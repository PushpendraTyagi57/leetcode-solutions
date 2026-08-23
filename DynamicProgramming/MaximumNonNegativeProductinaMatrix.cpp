#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<pair<ll, ll>>> dp;
    pair<ll, ll> solve(int row, int col, vector<vector<int>>& grid) {
        if (row == m - 1 && col == n - 1) {
            return {grid[row][col], grid[row][col]};
        }
        if (dp[row][col] != make_pair(LLONG_MIN, LLONG_MAX)) return dp[row][col];
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;
        if (row + 1 < m) {
            auto [downMax, downMin] = solve(row + 1, col, grid);
            maxVal = max({maxVal, grid[row][col] * downMax, grid[row][col] * downMin});
            minVal = min({minVal, grid[row][col] * downMax, grid[row][col] * downMin});
        }
        if (col + 1 < n) {
            auto [rightMax, rightMin] = solve(row, col + 1, grid);
            maxVal = max({maxVal, grid[row][col] * rightMax, grid[row][col] * rightMin});
            minVal = min({minVal, grid[row][col] * rightMax, grid[row][col] * rightMin});
        }
        return dp[row][col] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProduct, minProduct] = solve(0, 0, grid);
        return maxProduct < 0 ? -1 : maxProduct % MOD;
    }
};

int main () {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.maxProductPath(grid) << endl;
    return 0;
}