#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int minElement = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= minElement)
        {
            minElement = nums[i];
            minIndex = i;
        }
    }

    int maxElement = INT_MIN;
    int maxIndex = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] >= maxElement)
        {
            maxElement = nums[i];
            maxIndex = i;
        }
    }
    int firstIndex = 0;
    int lastIndex = n - 1;
    count += (lastIndex - minIndex);
    count += (maxIndex - firstIndex);
    if (maxIndex > minIndex)
        count--;
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << solve(nums) << "\n";
    return 0;
}