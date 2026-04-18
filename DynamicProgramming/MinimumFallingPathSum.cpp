#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (i == n) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int diagonalLeft = (j - 1 >= 0) ? matrix[i][j] + solve(i + 1, j - 1, matrix) : INT_MAX;
        int below = matrix[i][j] + solve(i + 1, j, matrix);
        int diagonalRight = (j + 1 < n) ? matrix[i][j] + solve(i + 1, j + 1, matrix) : INT_MAX;
        return dp[i][j] = min({diagonalLeft, below, diagonalRight});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.resize(n + 1, vector<int>(n + 1, INT_MAX));
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            minSum = min(minSum, solve(0, i, matrix));
        }
        return minSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    Solution obj;
    cout << obj.minFallingPathSum(matrix) << endl;
    return 0;
}