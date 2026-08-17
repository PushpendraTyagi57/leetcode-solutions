#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& stoneValue, vector<int>& prefixSum) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int score = 0;
        for (int mid = i; mid <= j - 1; mid++) {
            int leftSum = prefixSum[mid] - (i - 1 >= 0 ? prefixSum[i - 1] : 0);
            int rightSum = prefixSum[j] - prefixSum[mid];
            if (leftSum < rightSum) {
                score = max(score, leftSum + solve(i, mid, stoneValue, prefixSum));
            }
            else if (leftSum > rightSum) {
                score = max(score, rightSum + solve(mid + 1, j, stoneValue, prefixSum));
            }
            else {
                score = max({score, leftSum + solve(i, mid, stoneValue, prefixSum), rightSum + solve(mid + 1, j, stoneValue, prefixSum)});
            }
        }
        return dp[i][j] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum(n);
        prefixSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stoneValue[i];
        }
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, stoneValue, prefixSum);
    }
};

int main () {
    int n; cin >> n;
    vector<int> stoneValue(n);
    for (int i = 0; i < n; i++) cin >> stoneValue[i];
    Solution obj;
    cout << obj.stoneGameV(stoneValue) << endl;
    return 0;
}