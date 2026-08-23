#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftHalf = 0;
        int rightHalf = 0;
        int questionMarkLeftCount = 0;
        int questionMarkRightCount = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') questionMarkLeftCount++;
                else leftHalf += num[i] - '0';
            }
            else {
                if (num[i] == '?') questionMarkRightCount++;
                else rightHalf += num[i] - '0';
            }
        }
        int totalQuestionMark = questionMarkLeftCount + questionMarkRightCount;
        if (totalQuestionMark % 2 == 1) return true;
        int leftFinal = 2 * leftHalf + 9 * questionMarkLeftCount;
        int rightFinal = 2 * rightHalf + 9 * questionMarkRightCount;
        if (leftFinal == rightFinal) return false;
        return true;
    }
};

int main () {
    string num; cin >> num;
    Solution obj;
    cout << ((obj.sumGame(num)) ? "true" : "false") << endl;
    return 0;
}