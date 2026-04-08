#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    bool isPalindrome(int i, int j, string& s) {
        if (i >= j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = isPalindrome(i + 1, j - 1, s);
        return 0;
    }
    int countSubstrings(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n, -1));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) count++;
            }
        }
        return count;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.countSubstrings(s) << endl;
    return 0;
}