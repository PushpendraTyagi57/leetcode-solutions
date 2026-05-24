#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int idx, vector<int>& arr, int d) {
        if (dp[idx] != -1) return dp[idx];
        int result = 1;
        for (int left = idx - 1; left >= max(0, idx - d); left--) {
            if (arr[left] >= arr[idx]) break;
            result = max(result, 1 + solve(left, arr, d));
        }
        for (int right = idx + 1; right <= min(n - 1, idx + d); right++) {
            if (arr[right] >= arr[idx]) break;
            result = max(result, 1 + solve(right, arr, d));
        }
        return dp[idx] = result;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n + 1, -1);
        int result = 1;
        for (int i = 0; i < n; i++) {
            result = max(result, solve(i, arr, d));
        }
        return result;
    }
};

int main() {
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i];
    int d;
    cin >> d;
    Solution obj;
    cout << obj.maxJumps(arr, d) << endl;
    return 0;
}