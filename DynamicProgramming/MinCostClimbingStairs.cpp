#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& cost) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int oneStep = cost[i] + solve(i + 1, cost);
        int twoStep = cost[i] + solve(i + 2, cost);
        return dp[i] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n, -1);
        int case1 = solve(0, cost);
        int case2 = solve(1, cost);
        return min(case1, case2);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    Solution obj;
    cout << obj.minCostClimbingStairs(cost) << endl;
    return 0;
}