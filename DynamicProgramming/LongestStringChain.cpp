#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool isPredecessor(string b, string a) {
        if (b.size() != a.size() + 1) return false;
        int i = 0, j = 0;
        bool skipped = false;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }
    int solve(int i, int prev, vector<string>& words) {
        if (i >= n) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int skip = solve(i + 1, prev, words);
        int take = 0;
        if (prev == -1 || isPredecessor(words[i], words[prev]))
            take = 1 + solve(i + 1, i, words);
        return dp[i][prev + 1] = max(skip, take);
            
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        dp.resize(n, vector<int>(n + 1, - 1));
        return solve(0, -1, words);
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    Solution obj;
    cout << obj.longestStrChain(words) << endl;
    return 0;
}