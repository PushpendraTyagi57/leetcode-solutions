class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> seen(26, false);
        int count = 0;
        for (char c : s) {
            if (seen[c - 'a'] != true) {
                seen[c - 'a'] = true;
                count++;
            }
        }
        return count;
    }
};