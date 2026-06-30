#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int n = s.size(), count = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            lastSeen[idx] = i;
            if (lastSeen[0] == -1 || lastSeen[1] == -1 || lastSeen[2] == -1) continue;
            count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
        return count;
    }
};

int main() {
    string s; cin >> s;
    Solution obj;
    cout << obj.numberOfSubstrings(s) << endl;
    return 0;
}