#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    long firstNSum(int count) {
        long sum = 0;
        for (long i = 1; i <= count; i++) sum += (i) % MOD;
        return sum;
    }
    int countHomogenous(string s) {
        int count = 0;
        int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int size = j - i;
            count += (firstNSum(size)) % MOD;
            i = j;
        }
        return count;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.countHomogenous(s) << endl;
    return 0;
}