#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, int time, vector<int>& satisfaction) {
        if (idx >= n) return 0;
        if (dp[idx][time] != -1) return dp[idx][time];
        int cook = (satisfaction[idx] * time) + solve(idx + 1, time + 1, satisfaction);
        int noCook = solve(idx + 1, time, satisfaction);
        return dp[idx][time] = max(cook, noCook);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        dp.assign(n, vector<int>(n + 1, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(0, 1, satisfaction);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    cin >> m;
    vector<int> satisfaction(m);
    for (int i = 0; i < m; i++) {
        cin >> satisfaction[i];
    }
    Solution* obj = new Solution();
    cout << obj->maxSatisfaction(satisfaction) << "\n";
    return 0;
}