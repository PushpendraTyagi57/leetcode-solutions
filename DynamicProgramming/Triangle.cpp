#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& triangle) {
        if (i == n) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int case1 = triangle[i][j] + solve(i + 1, j, triangle);
        int case2 = triangle[i][j] + solve(i + 1, j + 1, triangle);
        return dp[i][j] = min(case1, case2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.resize(n);
        for (int i = 0; i < n; i++)
            dp[i].resize(i + 1, INT_MAX);
        return solve(0, 0, triangle);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
        triangle[i].resize(i + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            cin >> triangle[i][j];
        }
    }
    Solution obj;
    cout << obj.minimumTotal(triangle) << endl;
    return 0;
}