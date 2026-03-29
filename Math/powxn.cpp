#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long m = n;
        if (m < 0) {
            x = 1 / x;
            m = -m;
        }
        while (m > 0) {
            if (m % 2 == 1) {
                ans *= x;
                m -= 1;
            }
            else {
                x *= x;
                m /= 2;
            }
        }
        return ans;
    }
};

int main() {
    double x;
    int n;
    cin >> x >> n;
    Solution obj;
    cout << obj.myPow(x, n) << endl;
    return 0;
}