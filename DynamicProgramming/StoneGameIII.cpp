#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int idx, vector<int>& stoneValue) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int result = stoneValue[idx] - solve(idx + 1, stoneValue);
        if (idx + 1 < n) result = max(result, stoneValue[idx] + stoneValue[idx + 1] - solve(idx + 2, stoneValue));
        if (idx + 2 < n) result = max(result, stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - solve(idx + 3, stoneValue));
        return dp[idx] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, -1);
        int diff = solve(0, stoneValue);
        if (diff > 0) return "Alice";
        else if (diff < 0) return "Bob";
        return "Tie";
    }
};

int main () {
    int m; cin >> m;
    vector<int> stoneValue(m);
    for (int i = 0; i < m; i++) cin >> stoneValue[i];
    Solution obj;
    cout << obj.stoneGameIII(stoneValue) << endl;
    return 0;
}