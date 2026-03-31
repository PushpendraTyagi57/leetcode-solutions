#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }   
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowels;
        string result(n, '#');
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
            else {
                result[i] = s[i];
            }
        }
        sort(vowels.begin(), vowels.end());
        int v = 0;
        for (int i = 0; i < n; i++) {
            if (result[i] != '#') continue;
            else {
                result[i] = vowels[v];
                v++;
            }
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.sortVowels(s) << endl;
    return 0;
}