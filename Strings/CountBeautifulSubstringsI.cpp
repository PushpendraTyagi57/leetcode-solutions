#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int vowelCount = 0, consonantCount = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) vowelCount++;
                else consonantCount++;
                if (vowelCount == consonantCount) {
                    if ((vowelCount * consonantCount) % k == 0) count++;
                }
            }
        }
        return count;
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;
    Solution obj;
    cout << obj.beautifulSubstrings(s, k) << endl;
    return 0;
}