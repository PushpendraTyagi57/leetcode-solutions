class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int i = 0; i < m; i++) {
            mp1[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            mp2[t[i]]++;
        }
        if (mp1 == mp2) return true;
        return false;
    }
};