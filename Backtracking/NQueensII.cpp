#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& grid, int& n) {
        int i = row - 1, j = col;
        while (i >= 0) {
            if (grid[i][j] == 'Q') return false;
            i--;
        }
        i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (grid[i][j] == 'Q') return false;
            i--, j--;
        }
        i = row - 1, j = col + 1;
        while (i >= 0 && j < n) {
            if (grid[i][j] == 'Q') return false;
            i--, j++;
        }
        return true;
    }
    int solve(int row, vector<vector<char>>& grid, int& n) {
        if (row >= n) {
            return 1;
        }
        int ans = 0;
        for (int col = 0; col < n; col++) {
            grid[row][col] = 'Q';
            if (isValid(row, col, grid, n)) ans += solve(row + 1, grid, n);
            grid[row][col] = '.';
        }
        return ans;
    } 
    int totalNQueens(int n) {
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        return solve(0, grid, n);
    }
};

int main() {
    int n; cin >> n;
    Solution obj;
    cout << obj.totalNQueens(n);
    return 0;
}