#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        if (n == 1)
            return true;
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    int ans = obj.isUgly(n);
    if (ans == 1)
        cout << "True";
    else
        cout << "False";
    return 0;
}