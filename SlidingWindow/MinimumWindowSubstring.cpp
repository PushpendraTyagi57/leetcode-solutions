#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> freq(256, 0);
        for (char& ch : t) freq[ch]++;
        int minLength = INT_MAX, startIndex = -1;
        int count = 0;
        int i = 0, j = 0;
        while (j < n) {
            char ch = s[j];
            if (freq[ch] > 0) count += 1;
            freq[ch]--;
            while (count == m) {
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    startIndex = i;
                }
                freq[s[i]]++;
                if (freq[s[i]] > 0) count--;
                i++;
            }
            j++;
        }
        return (startIndex == -1 ? "" : s.substr(startIndex, minLength));
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.minWindow(s, t) << endl;
    return 0;
}