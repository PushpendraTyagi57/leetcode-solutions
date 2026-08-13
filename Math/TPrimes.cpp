#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<bool> sieve(1000001, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == true)
        {
            for (long long j = 1LL * i * i; j < sieve.size(); j += i)
            {
                sieve[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        long long squareRoot = sqrt(nums[i]);
        if (squareRoot * squareRoot != nums[i])
        {
            cout << "NO\n";
        }
        else if (sieve[squareRoot])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}