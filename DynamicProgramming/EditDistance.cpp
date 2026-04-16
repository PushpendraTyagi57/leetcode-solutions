#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(string& word1, string& word2, int i, int j) {
        if (i == m) return n - j;
        else if (j == n) return m - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i + 1, j + 1);
        else {
            int insertChar = 1 + solve(word1, word2, i, j + 1);
            int deleteChar = 1 + solve(word1, word2, i + 1, j);
            int replaceChar = 1 + solve(word1, word2, i + 1, j + 1);
            return dp[i][j] = min({insertChar, deleteChar, replaceChar});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        dp.resize(m, vector<int>(n, -1));
        return solve(word1, word2, 0, 0);
    }
};

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    Solution obj;
    cout << obj.minDistance(word1, word2) << endl;
    return 0;
}