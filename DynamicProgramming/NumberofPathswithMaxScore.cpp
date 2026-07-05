#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    pair<int, int> dp[101][101];

    int getNum(char ch) {
        return ch == 'S' ? 0 : ch - '0';
    }

    bool isValid(int row, int col, vector<string>& board) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') return {0, 1};
        if (board[i][j] == 'X') return {0, 0};

        if (dp[i][j] != make_pair(-1, -1)) return dp[i][j]; 

        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        char ch = board[i][j];

        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0) upScore += getNum(ch);
        }

        if (isValid(i, j - 1, board)) {
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0) leftScore += getNum(ch);
        }

        if (isValid(i - 1, j - 1, board)) {
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0) diagScore += getNum(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        }
        else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > leftScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore;
                bestPaths = diagPaths;
            }
        }
        else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore;
                bestPaths = upPaths;
            } 
        }
        else {
            bestScore = upScore;
            bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore;
                bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore;
                bestPaths = diagPaths;
            }
        }

        return dp[i][j] = {bestScore, bestPaths % MOD};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = {-1, -1};
            }
        }
        pair<int, int> result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};

int main() {
    int m; cin >> m;
    vector<string> board(m);
    for (int i = 0; i < m; i++) {
        cin >> board[i];
    }
    Solution obj;
    vector<int> result = obj.pathsWithMaxScore(board);
    cout << "{" << result[0] << ", " << result[1] << "}" << endl;
    return 0;
}