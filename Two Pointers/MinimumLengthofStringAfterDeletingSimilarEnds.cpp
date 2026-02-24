#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (i == j)
                return 1;
            if (s[i] == s[j]) {
                char c = s[i];
                int m = i;
                while (s[m] == c && m < j)
                    m++;
                char d = s[j];
                int n = j;
                while (s[n] == d && n > i)
                    n--;
                i = m;
                j = n;
            }
            else
                return j - i + 1;
        }
        return 0;
    }
};

int main () {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minimumLength(s) << endl;
}