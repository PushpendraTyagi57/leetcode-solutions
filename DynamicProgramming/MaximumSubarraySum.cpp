#include <bits/stdc++.h>

using namespace std;

int maximumSum(vector<int> &nums)
{
    int n = nums.size();
    int currSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < n; i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    std::ios::sync_with_stdio(false);
std:
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maximumSum(nums);
    return 0;
}