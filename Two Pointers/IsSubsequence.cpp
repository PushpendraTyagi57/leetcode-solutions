class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = s.size(), n = t.size();
        while (j < n && i < m) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == m;
    }
};