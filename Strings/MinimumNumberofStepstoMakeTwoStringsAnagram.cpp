#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        int result = 0;
        for (int i = 0; i < 26; i++)
            if (count[i] > 0) result += count[i];
        return result;
    }
};

int main () {
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.minSteps(s, t) << endl;
    return 0;
}