#include <bits/stdc++.h>

using namespace std;

int dp[502][502];
class Solution {
public:
    int solve(int i, int j, vector<int>& piles) {
        if (i > j) return 0;
        if (i == j) return piles[i];
        if (dp[i][j] != -1) return dp[i][j];
        int take_i = piles[i] + min(solve(i + 2, j, piles), solve(i + 1, j - 1, piles));
        int take_j = piles[j] + min(solve(i, j - 2, piles), solve(i + 1, j - 1, piles));
        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int totalSum = 0;
        for (int& pile : piles) totalSum += pile;
        memset(dp, -1, sizeof(dp));
        int aliceScore = solve(0, n - 1, piles);
        int bobScore = totalSum - aliceScore;
        return aliceScore > bobScore;
    }
};

int main() {
    int n; cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) cin >> piles[i];
    Solution obj;
    cout << ((obj.stoneGame(piles) == 1) ? "true" : "false") << endl;
    return 0;
}