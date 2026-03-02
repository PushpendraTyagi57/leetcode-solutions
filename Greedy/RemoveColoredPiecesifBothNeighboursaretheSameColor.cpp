#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int aliceTurns = 0, bobTurns = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                aliceTurns++;
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                bobTurns++;
        }
        return aliceTurns > bobTurns;
    }
};

int main() {
    string colors;
    cin >> colors;
    Solution obj;
    bool result = obj.winnerOfGame(colors);
    cout << result << endl;
    return 0;
}