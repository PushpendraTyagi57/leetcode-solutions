#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for (char &move : moves) {
            if (move == 'U') i--;
            else if (move == 'D') i++;
            else if (move == 'L') j--;
            else j++;
        }
        if (i == 0 && j == 0) return true;
        return false;
    }
};

int main() {
    string moves;
    cin >> moves;
    Solution obj;
    bool ans = obj.judgeCircle(moves);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}