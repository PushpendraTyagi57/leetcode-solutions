#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long totalShifts = 0;
        for (int& shift : shifts)
            totalShifts += shift;
        for (int i = 0; i < s.size(); i++) {
            int currShifts = totalShifts % 26;
            s[i] = 'a' + (s[i] + currShifts - 'a') % 26;
            totalShifts -= shifts[i];
        }
        return s;
    }
};

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<int> shifts(n);
    for (int i = 0; i < n; i++) cin >> shifts[i];
    Solution sol;
    cout << sol.shiftingLetters(s, shifts) << endl;
    return 0;
}