#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int row, int col) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }

    int dfs(int row, int col, vector<vector<int>>& matrix) {
        if (dp[row][col] != -1) return dp[row][col];
        int ans = 1;
        for (auto& dir : directions) {
            int new_i = row + dir[0];
            int new_j = col + dir[1];
            if (isValid(new_i, new_j) && matrix[new_i][new_j] < matrix[row][col])
                ans = max(ans, 1 + dfs(new_i, new_j, matrix));
        }
        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        int result = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(i, j, matrix));
            }
        }
        return result;
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> matrix(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    cout << obj.longestIncreasingPath(matrix) << endl;
    return 0;
}