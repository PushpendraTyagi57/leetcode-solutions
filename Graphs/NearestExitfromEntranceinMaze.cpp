#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(int row, int col, int& m, int& n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    bool isBorder(int row, int col, int& m, int& n) {
        return (row == 0 || row == m - 1 || col == 0 || col == n - 1);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                auto curr = que.front();
                que.pop();
                int row = curr.first;
                int col = curr.second;
                if ((row != entrance[0] || col != entrance[1]) && isBorder(row, col, m, n)) return steps;
                for (auto& dir : directions) {
                    int new_i = row + dir[0];
                    int new_j = col + dir[1];
                    if (isValid(new_i, new_j, m, n) && maze[new_i][new_j] == '.') {
                        maze[new_i][new_j] = '+';
                        que.push({new_i, new_j});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> maze(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    vector<int> entrance(2);
    cin >> entrance[0] >> entrance[1];
    Solution obj;
    cout << obj.nearestExit(maze, entrance) << endl;
    return 0;
}