#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) dp[i][j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
                else {
                    int down = (i + 1 >= m) ? INT_MAX : dp[i + 1][j];
                    int right = (j + 1 >= n) ? INT_MAX : dp[i][j + 1];
                    int result = min(down, right) - dungeon[i][j];
                    dp[i][j] = (result > 0) ? result : 1;
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dungeon(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> dungeon[i][j];
    Solution obj;
    cout << obj.calculateMinimumHP(dungeon) << endl;
    return 0;
}