#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = nums[0];
        int maxSum = nums[0];

        int currSumMax = nums[0];
        int currSumMin = nums[0];
        for (int i = 1; i < n; i++) {
            currSumMax = max(nums[i], nums[i] + currSumMax);
            maxSum = max(maxSum, currSumMax);

            currSumMin = min(nums[i], nums[i] + currSumMin);
            minSum = min(minSum, currSumMin);
        }
        return max(maxSum, abs(minSum));
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.maxAbsoluteSum(nums) << endl;
    return 0;
}