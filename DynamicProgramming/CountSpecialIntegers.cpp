#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[11][2][2][1024];
    int solve(string& s, int idx, int tight, int lz, int mask) {
        if (idx == s.size()) return 1;
        if (dp[idx][tight][lz][mask] != -1) return dp[idx][tight][lz][mask];
        int lb = 0;
        int ub = (tight) ? s[idx] - '0' : 9;
        int result = 0;
        for (int dig = lb; dig <= ub; dig++) {
            int newTight = tight;
            if (tight) {
                if (dig < s[idx] - '0') newTight = 0;
                else newTight = 1;
            }
            if (lz == 1 && dig == 0) result += solve(s, idx + 1, newTight, 1, mask);
            else {
                if ((mask & (1 << dig)) != 0) continue;
                int newMask = mask | (1 << dig);
                result += solve(s, idx + 1, newTight, 0, newMask);
            }
        }
        return dp[idx][tight][lz][mask] = result;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1, 0) - 1;
    }
};

int main() {
    int n; cin >> n;
    Solution obj;
    cout << obj.countSpecialNumbers(n) << endl;
    return 0;
}