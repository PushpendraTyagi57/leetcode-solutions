#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int prev, vector<vector<int>>& pairs) {
        if (i >= n) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int skip = solve(i + 1, prev, pairs);
        int take = 0;
        if (prev == -1 || pairs[i][0] > pairs[prev][1])
            take = 1 + solve(i + 1, i, pairs);
        return dp[i][prev + 1] = max(skip, take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        dp.resize(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1, pairs);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> pairs[i][j];
    Solution obj;
    cout << obj.findLongestChain(pairs) << endl;
    return 0;
}