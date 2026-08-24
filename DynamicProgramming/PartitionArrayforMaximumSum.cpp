#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int n;
    int dp[501];
    int solve(int i, vector<int>& arr, int& k) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int currMax = -1;
        int result = 0;
        for (int j = i; j < n && j - i + 1 <= k; j++) {
            currMax = max(currMax, arr[j]);
            result = max(result, (currMax * (j - i + 1)) + solve(j + 1, arr, k));
        }
        return dp[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};

int main () {
    int m; cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    int k; cin >> k;
    Solution obj;
    cout << obj.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}