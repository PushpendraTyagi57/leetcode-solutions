#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    bool palindromeSolve(int i, int j, string& s) {
        if (i >= j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = palindromeSolve(i + 1, j - 1, s);
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n, -1));
        int longest = INT_MIN;
        int starti = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (palindromeSolve(i, j, s)) {
                    if (j - i + 1 > longest) {
                        longest = j - i + 1;
                        starti = i;
                    }
                }
            }
        }
        string result = "";
        for (int i = starti; i < starti + longest; i++)
            result.push_back(s[i]);
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.longestPalindrome(s) << endl;
    return 0;
}