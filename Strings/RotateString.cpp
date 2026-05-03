#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size(), n = goal.size();
        if (m != n) return false;
        for (int i = 0; i < m; i++) {
            if (s[i] == goal[0]) {
                int j = i;
                int v = 0;
                bool possible = true;
                while (v < n) {
                    if (s[j % n] != goal[v]) {
                        possible = false;
                        break;
                    }
                    else {
                        j++;
                        v++;
                    }
                }
                if (possible) return true;
            }
        }
        return false;
    }
};

int main() {
    string s, goal;
    cin >> s >> goal;
    Solution obj;
    bool ans = obj.rotateString(s, goal);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}