#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int degree = 0;
        for (int i = 0; i < n; i++) {
            int alphabetIndex = s[i] - 'a';
            int reversedAlphabetIndex = 26 - alphabetIndex;
            degree += (reversedAlphabetIndex * (i + 1));
        }
        return degree;
    }
};

int main () {
    string s; cin >> s;
    Solution* obj = new Solution();
    cout << obj->reverseDegree(s) << endl;
    return 0;
}