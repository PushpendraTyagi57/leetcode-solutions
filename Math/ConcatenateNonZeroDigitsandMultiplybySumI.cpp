#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0;
        while (n > 0) {
            if (n % 10 == 0) n /= 10;
            else {
                num = num * 10;
                num += n % 10;
                n /= 10;
            }
        }
        int x = 0;
        int sumDigits = 0;
        while (num > 0) {
            x = x * 10;
            x += num % 10;
            sumDigits += num % 10;
            num /= 10;
        }
        return (long long) x * (long long) sumDigits;

    }
};

int main() {
    int n; cin >> n;
    Solution sol;
    cout << sol.sumAndMultiply(n) << endl;
    return 0;
}