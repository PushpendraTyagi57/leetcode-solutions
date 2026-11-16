#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<string, bool> dp;
    bool solve(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.size() != s2.size())
            return false;
        
        string key = s1 + "_" + s2;
        if (dp.find(key) != dp.end())
            return dp[key];
        
        int n = s1.size();
        for (int i = 1; i < n; i++) {
            bool notSwap = solve(s1.substr(0, i), s2.substr(0, i)) &&
                            solve(s1.substr(i, n - i), s2.substr(i, n - i));
            if (notSwap)
                return dp[key] = true;

            bool swap = solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                            solve(s1.substr(i, n - i), s2.substr(0, n - i));

            if (swap)
                return dp[key] = true;
        }
        return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    Solution* obj = new Solution();
    cout << ((obj->isScramble(s1, s2)) ? "true" : "false") << "\n";
    return 0;
}