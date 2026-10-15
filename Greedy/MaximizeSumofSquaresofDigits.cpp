#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result = "";
        for (int i = 0; i < num; i++) {
            if (sum == 0) result += '0';
            else if (sum < 9) {
                result += to_string(sum);
                sum = 0;
            }
            else {
                result += '9';
                sum -= 9;
            }
        }

        if (sum > 0) return "";
        return result;
    }
};

int main () {
    int num, sum;
    cin >> num >> sum;
    Solution* obj = new Solution();
    cout << obj->maxSumOfSquares(num, sum) << endl;
    return 0;
}