#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        vector<int> dp(n, 0);
        dp[n - 1] = prefixSum[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - dp[i + 1];
            int skip = dp[i + 1];
            dp[i] = max(take, skip);
        }
        return dp[1];
    }
};

int main () {
    int n; cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    Solution obj;
    cout << obj.stoneGameVIII(stones) << endl;
    return 0;
}