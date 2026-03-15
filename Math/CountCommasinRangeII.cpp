#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        else if (n < 1000000) return (n - 999) + countCommas(999);
        else if (n < 1000000000) return 2 * (n - 999999) + countCommas(999999);
        else if (n < 1000000000000) return 3 * (n - 999999999) + countCommas(999999999);
        else if (n < 1000000000000000) return 4 * (n - 999999999999) + countCommas(999999999999);
        return 5 * (n - 999999999999999) +  countCommas(999999999999999);
    }
};

int main() {
    long long n;
    cin >> n;
    Solution obj;
    long long ans = obj.countCommas(n);
    cout << ans << endl;
    return 0;
}