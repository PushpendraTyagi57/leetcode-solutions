#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> mp(256, -1);
        int i = 0, j = 0;
        int maxLen = 0;
        while (j < n) {
            if (mp[s[j]] != -1) {
                if (mp[s[j]] >= i) i = mp[s[j]] + 1;
            }
            maxLen = max(maxLen, j - i + 1);
            mp[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};

int main() {
    string s; cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}