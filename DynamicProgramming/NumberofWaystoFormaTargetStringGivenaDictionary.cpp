#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<long long>>& freq, string& target) {
        if (i >= m)
            return 1;
        if (j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int skip = solve(i, j + 1, freq, target);
        long long take = 1LL * freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target);

        return dp[i][j] = (take + skip) % MOD;
    }
    int numWays(vector<string>& words, string target) {
        m = target.size();
        n = words[0].size();

        vector<vector<long long>> freq(26, vector<long long>(n, 0));
        for (int col = 0; col < n; col++) {
            for (auto& word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, freq, target);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    cin >> x;
    vector<string> words(x);
    for (int i = 0; i < x; i++) {
        cin >> words[i];
    }

    string target;
    cin >> target;
    Solution *obj = new Solution();
    cout << obj->numWays(words, target) << "\n";
    return 0;
}