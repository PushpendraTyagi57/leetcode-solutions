class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        string result = s;
        if (k == 1) {
            for (int l = 1; l <= n - 1; l++) {
                string temp = s.substr(l) + s.substr(0, l);
                result = min(result, temp);
            }
        }
        else {
            sort(s.begin(), s.end());
            return s;
        }
        return result;
    }
};