#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        vector<unordered_map<long long, int>> mp(n);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)nums[i] - nums[j];
                auto it = mp[j].find(diff);

                int countJ = (it == mp[j].end() ? 0 : it->second);

                mp[i][diff] += countJ + 1;
                result += countJ;
            }
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution *obj = new Solution();
    cout << obj->numberOfArithmeticSlices(nums) << "\n";
    return 0;
}