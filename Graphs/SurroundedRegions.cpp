#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        board[row][col] = '#';
        for (auto& dir : directions) {
            int new_i = row + dir[0];
            int new_j = col + dir[1];
            if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
            if (board[new_i][new_j] == 'O') dfs(new_i, new_j, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1) dfs(i, j, board);
                    else continue;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<char>> board(x, vector<char>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> board[i][j];
        }
    }
    Solution sol;
    sol.solve(board);
    return 0;
}