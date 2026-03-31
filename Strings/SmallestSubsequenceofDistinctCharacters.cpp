#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        for (int i = 0; i < n; i++)
            lastIndex[s[i] - 'a'] = i;
        string result;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (taken[ch - 'a']) continue;
            while (result.size() > 0 && result.back() > ch && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[ch - 'a'] = true;
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.smallestSubsequence(s) << endl;
    return 0;
}