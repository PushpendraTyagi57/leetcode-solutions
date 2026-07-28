#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char& ch : s) freq[ch - 'a']++;
        int startIdx = 0, endIdx = n - 1;
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (freq[i] == 1) {
                    int midIdx = n / 2;
                    s[midIdx] = (char) i + 'a';
                    freq[i] -= 1;
                }
                else {
                    s[startIdx++] = (char) i + 'a';
                    s[endIdx--] = (char) i + 'a';
                    freq[i] -= 2;
                }
            }
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.smallestPalindrome(s) << endl;
    return 0;
}