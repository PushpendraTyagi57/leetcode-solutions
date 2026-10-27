#include <bits/stdc++.h>

using namespace std;

long long freq[100001];
long long dp[100001];

long long solve(int num)
{
    if (num <= 0)
        return 0;
    if (dp[num] != -1)
        return dp[num];
    long long skip = solve(num - 1);
    long long take = 1LL * num * freq[num] + solve(num - 2);
    return dp[num] = max(take, skip);
}

int main()
{
    int n;
    cin >> n;
    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
        maxNum = max(maxNum, x);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(maxNum) << "\n";
    return 0;
}