#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    bool isValid(int startRow, int endRow, int startCol, int endCol, vector<string>& pizza) {
        for (int i = startRow; i <= endRow; i++) {
            for (int j = startCol; j <= endCol; j++) {
                if (pizza[i][j] == 'A')
                    return true;
            }
        }
        return false;
    }

    int solve(int row, int col, int cuts, vector<string>& pizza) {
        if (cuts == 0)
            return isValid(row, m - 1, col, n - 1, pizza);

        if (dp[row][col][cuts] != -1)
            return dp[row][col][cuts];
        
        long long ans = 0;
        for (int i = row; i < m - 1; i++) {
            bool upper = isValid(row, i, col, n - 1, pizza);
            bool lower = isValid(i + 1, m - 1, col, n - 1, pizza);
            if (upper && lower) {
                int next = solve(i + 1, col, cuts - 1, pizza);
                ans = (ans + next) % MOD;
            }
        }

        for (int i = col; i < n - 1; i++) {
            bool left = isValid(row, m - 1, col, i, pizza);
            bool right = isValid(row, m - 1, i + 1, n - 1, pizza);
            if (left && right) {
                int next = solve(row, i + 1, cuts - 1, pizza);
                ans = (ans + next) % MOD;
            }
        }

        return dp[row][col][cuts] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, k - 1, pizza);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    cin >> x;
    vector<string> pizza(x);
    for (int i = 0; i < x; i++) {
        cin >> pizza[i];
    }

    int k;
    cin >> k;

    Solution* obj = new Solution();
    cout << obj->ways(pizza, k) << "\n";
    return 0;
}