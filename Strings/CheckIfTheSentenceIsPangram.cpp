class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);
        for (char c : sentence) {
            seen[c - 'a'] = true;
        }
        for (int j = 0; j < seen.size(); j++) {
            if (seen[j] == false) return false;
        }
        return true;
    }
};