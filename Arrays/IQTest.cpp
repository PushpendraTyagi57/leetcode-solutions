#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n + 1);
    int evenCount = 0, oddCount = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];

        if (nums[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    if (evenCount == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                cout << i;
                break;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] % 2 == 1)
            {
                cout << i;
                break;
            }
        }
    }
    return 0;
}