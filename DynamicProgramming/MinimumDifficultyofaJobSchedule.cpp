#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, vector<int>& jobDifficulty, int d) {
        if (d == 1) {
            int maxD = jobDifficulty[idx];
            for (int i = idx; i < n; i++) maxD = max(maxD, jobDifficulty[i]);
            return maxD;
        }
        if (dp[idx][d] != -1) return dp[idx][d];
        int maxD = jobDifficulty[idx];
        int result = INT_MAX;
        for (int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);
            int currResult = maxD + solve(i + 1, jobDifficulty, d - 1);
            result = min(result, currResult);
        }
        return dp[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (d > n) return -1;
        dp.resize(n + 1, vector<int>(d + 1, -1));
        return solve(0, jobDifficulty, d);
    }
};

int main() {
    int m;
    cin >> m;
    vector<int> jobDifficulty(m);
    for (int i = 0; i < m; i++) cin >> jobDifficulty[i];
    int d;
    cin >> d;
    Solution obj;
    cout << obj.minDifficulty(jobDifficulty, d) << endl;
    return 0;
}