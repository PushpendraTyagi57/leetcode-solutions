#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, int prev, string& s) {
        if (idx >= n)
            return 0;

        if (dp[idx][prev] != -1)
            return dp[idx][prev];

        int flip = INT_MAX;
        int noFlip = INT_MAX;
        if (s[idx] == '0') {
            if (prev == 0) {
                flip = 1 + solve(idx + 1, 1, s);
                noFlip = solve(idx + 1, 0, s);
            }
            else { // prev == 1
                flip = 1 + solve(idx + 1, 1, s);
            }
        }
        else { // s[idx] == '1'
            if (prev == 0) {
                flip = 1 + solve(idx + 1, 0, s);
                noFlip = solve(idx + 1, 1, s);
            }
            else { // prev == 1
                noFlip = solve(idx + 1, 1, s);
            }
        }
        return dp[idx][prev] = min(flip, noFlip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.size();
        dp.assign(n + 1, vector<int>(2, -1));
        return solve(0, 0, s);
    }
};

int main() {
    string s;
    cin >> s;
    Solution* obj = new Solution();
    cout << obj->minFlipsMonoIncr(s) << "\n";
    return 0;

}