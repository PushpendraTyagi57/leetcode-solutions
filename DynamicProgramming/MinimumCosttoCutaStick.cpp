#include <bits/stdc++.h>

using namespace std;

int dp[103][103];
class Solution {
public:
    int solve(int left, int right, vector<int>& cuts) {
        if (right - left < 2) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int result = INT_MAX;
        for (int i = left + 1; i <= right - 1; i++) {
            int cost = (cuts[right] - cuts[left]) + solve(left, i, cuts) + solve(i, right, cuts);
            result = min(result, cost);
        }
        return dp[left][right] = result;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, cuts.size() - 1, cuts);
    }
};

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> cuts(k);
    for (int i = 0; i < k; i++) cin >> cuts[i];
    Solution obj;
    cout << obj.minCost(n, cuts) << endl;
    return 0;
}