#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i = 0, j = 0;
        int trueCount = 0, falseCount = 0;
        int maxSize1 = 0;
        while (j < n) {
            if (answerKey[j] == 'F') falseCount++;
            while (falseCount > k) {
                if (answerKey[i] == 'F')
                    falseCount--;
                i++;
            }
            maxSize1 = max(maxSize1, j - i + 1);
            j++;
        }
        i = 0, j = 0;
        trueCount = 0;
        int maxSize2 = 0;
        while (j < n) {
            if (answerKey[j] == 'T') trueCount++;
            while (trueCount > k) {
                if (answerKey[i] == 'T')
                    trueCount--;
                i++;
            }
            maxSize2 = max(maxSize2, j - i + 1);
            j++;
        }
        int result = max(maxSize1, maxSize2);
        return result;
    }
};

int main() {
    string answerKey;
    cin >> answerKey;
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maxConsecutiveAnswers(answerKey, k) << endl;
    return 0;
}