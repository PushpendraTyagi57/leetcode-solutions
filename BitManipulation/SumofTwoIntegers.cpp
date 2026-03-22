#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (unsigned int) (a & b) << 1;
        return getSum(sum, carry);   
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.getSum(a, b) << endl;
    return 0;
}