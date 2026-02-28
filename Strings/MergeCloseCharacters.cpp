#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k) {
        while (true) {
            bool merged = false;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == s[j] && j - i <= k) {
                        s.erase(j, 1);
                        merged = true;
                        break;
                    }
                }
                if (merged) break;
            }
            if (!merged) break;
        }
        return s;
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;
    Solution obj;
    cout << obj.mergeCharacters(s, k);
    return 0;
}