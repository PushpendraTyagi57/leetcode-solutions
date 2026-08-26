#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    int dp[51][51];
    int solve(int i, int j, vector<int>& values) {
        if (j - i <= 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int result = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int currAns = solve(i, k, values) + (values[i] * values[j] * values[k]) + solve(k, j, values);
            result = min(result, currAns);
        }
        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, values);
    }
};

int main () {
    int m; cin >> m;
    vector<int> values(m);
    for (int i = 0; i < m; i++) {
        cin >> values[i];
    }
    Solution obj;
    cout << obj.minScoreTriangulation(values) << endl;
    return 0;
}