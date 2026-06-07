#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);
        for (vector<int>& vec : shifts) {
            int L = vec[0];
            int R = vec[1];
            int dir = vec[2];
            if (dir == 1) diff[L]++;
            else diff[L]--;
            if (R + 1 < n) {
                if (dir == 1) diff[R + 1]--;
                else diff[R + 1]++;
            }
        }
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';
            curr = (curr + diff[i]) % 26;
            if (curr < 0) curr += 26;
            s[i] = curr + 'a';
        }
        return s;
    }
};

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<vector<int>> shifts(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> shifts[i][j];
    Solution obj;
    cout << obj.shiftingLetters(s, shifts) << endl;
    return 0;
}