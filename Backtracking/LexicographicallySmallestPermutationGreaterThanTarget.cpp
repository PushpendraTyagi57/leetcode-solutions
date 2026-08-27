#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string result = "";
    bool solve(int idx, string curr, bool greater, string& target, vector<int>& freq) {
        if (idx == target.size()) {
            if (greater) {
                result = curr;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0) continue;
            if (greater == false && ch < target[idx]) continue;

            curr.push_back(ch);
            freq[ch - 'a']--;
            bool isGreater = greater || ch > target[idx];
            if (solve(idx + 1, curr, isGreater, target, freq)) return true;
            curr.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;
        string curr;
        solve(0, curr, false, target, freq);
        return result;
    }
};

int main () {
    string s, target;
    cin >> s >> target;
    Solution obj;
    cout << obj.lexGreaterPermutation(s, target) << endl;
    return 0;
}