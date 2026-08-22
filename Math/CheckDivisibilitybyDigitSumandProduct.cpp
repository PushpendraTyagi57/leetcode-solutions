#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        long long digitSum = 0;
        long long digitProduct = 1;
        int num = n;
        while (num > 0) {
            digitSum += num % 10;
            digitProduct *= num % 10;
            num /= 10;
        }
        if (n % (0LL + digitSum + digitProduct) == 0) return true;
        return false;
    }
};

int main () {
    int n; cin >> n;
    Solution obj;
    cout << ((obj.checkDivisibility(n)) ? "true" : "false") << endl;
    return 0;
}