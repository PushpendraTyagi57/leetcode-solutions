#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i, string& s, int& n) {
        if (dp[i] != -1) return dp[i];
        if (i == n) return dp[i] = 1;
        if (s[i] == '0') return dp[i] = 0;
        int result = solve(i + 1, s, n);
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) 
                result += solve(i + 2, s, n);
        }
        return dp[i] = result;
    }
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n + 1, -1);
        return solve(0, s, n);
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.numDecodings(s) << endl;
    return 0;
}