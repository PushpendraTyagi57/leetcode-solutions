#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;
        unordered_set<int> st;
        int deletions = 0;
        for (int i = 0; i < freq.size(); i++) {
            while (freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--;
                deletions++;
            }
            if (freq[i] > 0)
                st.insert(freq[i]);
        }
        return deletions;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minDeletions(s) << endl;
    return 0;
}