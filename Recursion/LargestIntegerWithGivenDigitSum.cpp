#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int idx, int num, int& n, int& s) {
        if (idx == n) {
            int digitSum = 0;
            int temp = num;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            if (digitSum == s) return temp;
            return -1;
        }
        int ans = INT_MIN;
        for (int i = 9; i >= 0; i--) {
            if (idx == 0 && i == 0) continue;
            ans = max(ans, solve(idx + 1, num * 10 + i, n, s));
        }
        return ans == INT_MIN ? -1 : ans;
    }
    int largestInteger(int n, int s) {
        if (s == 0) return 0;
        return solve(0, 0, n, s);
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    Solution obj;
    cout << obj.largestInteger(n, s) << endl;
    return 0;
}