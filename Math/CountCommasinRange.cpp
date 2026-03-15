#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;
        else if (n < 10000) return 1 + countCommas(n - 1);
        return 1 + countCommas(n - 1);
    }
};

int main() {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.countCommas(n) << endl;
    return 0;
}