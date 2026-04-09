#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(int i, string s, unordered_set<string>& wordSet) {
        if (i == n) return dp[i] = 1;
        if (dp[i] != -1) return dp[i];
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];
            if (wordSet.find(temp) != wordSet.end())
                if (solve(j + 1, s, wordSet)) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.resize(n + 1, -1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return solve(0, s, wordSet);
    }
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) cin >> wordDict[i];
    Solution obj;
    bool ans = obj.wordBreak(s, wordDict);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}