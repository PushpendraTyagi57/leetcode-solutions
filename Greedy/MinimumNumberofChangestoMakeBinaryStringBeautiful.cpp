#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = 1; i < n; i += 2)
        {
            if (s[i] != s[i - 1])
                count++;
        }
        return count;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    Solution *obj = new Solution();

    cout << obj->minChanges(s) << "\n";
    return 0;
}