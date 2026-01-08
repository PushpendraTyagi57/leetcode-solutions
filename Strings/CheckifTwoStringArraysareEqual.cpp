class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int m = 0, n = 0;
        while (i < word1.size() && m < word2.size()) {
            if (word1[i][j] != word2[m][n]) return false;
            j++;
            n++;
            if (j == word1[i].size()) {
                i++;
                j = 0;
            }
            if (n == word2[m].size()) {
                m++;
                n = 0;
            }
        }
        return i == word1.size() && m == word2.size();
    }
};