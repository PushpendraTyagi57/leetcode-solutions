class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        int i = 0;
        int prefixSize = 0;
        int distinctChars = 0;
        int residues = 0;
        unordered_set<char> st;
        while (i < n) {
            st.insert(s[i]);
            prefixSize = i + 1;
            distinctChars = st.size();
            if (distinctChars > 2) break;
            if (prefixSize % 3 == distinctChars) residues++;
            i++;
        }
        return residues;
    }
};