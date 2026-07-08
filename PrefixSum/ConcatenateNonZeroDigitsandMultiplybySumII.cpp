#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> digitSum(n, 0);
        vector<ll> numUpTo(n, 0);
        vector<int> nonZeroDigits(n, 0);
        vector<ll> pow10(n + 1, 0);

        digitSum[0] = s[0] - '0';
        numUpTo[0] = s[0] - '0';
        nonZeroDigits[0] = ((s[0] - '0' != 0) ? 1 : 0);

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';

            digitSum[i] = digitSum[i - 1] + digit;

            if (digit != 0) {
                numUpTo[i] = ((numUpTo[i - 1] * 10) + digit) % MOD;
            }
            else {
                numUpTo[i] = numUpTo[i - 1];
            }

            nonZeroDigits[i] = nonZeroDigits[i - 1] + ((digit != 0) ? 1 : 0);
        }

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        int q = queries.size();
        vector<int> answer(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll sumOfDigits = digitSum[r] - ((l == 0) ? 0 : digitSum[l - 1]);

            int numBefore = (l == 0) ? 0 : numUpTo[l - 1];
            int k = nonZeroDigits[r] - ((l == 0) ? 0 : nonZeroDigits[l - 1]);

            ll x = (numUpTo[r] - (numBefore * pow10[k] % MOD) + MOD) % MOD;
            
            answer[i] = (int) ((x * sumOfDigits) % MOD);
        }
        return answer;
    }
};

int main() {
    string s; cin >> s;
    int q; cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<int> ans = obj.sumAndMultiply(s, queries);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}