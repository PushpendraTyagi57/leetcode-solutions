#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool different(int num) {
        bool possible = false;
        while (num > 0) {
            int lastDigit = num % 10;
            if (lastDigit == 3 || lastDigit == 4 || lastDigit == 7) return false;
            if (lastDigit == 2 || lastDigit == 5 || lastDigit == 6 || lastDigit == 9) possible = true;
            num /= 10;
        }
        if (possible) return true;
        return false;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (different(i)) count++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.rotatedDigits(n) << endl;
    return 0;
}