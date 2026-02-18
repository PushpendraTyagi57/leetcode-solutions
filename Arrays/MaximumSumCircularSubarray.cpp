class Solution {
public:
    int kadaneMax(vector<int>& nums, int n) {
        int sum = 0, max_i = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > max_i) max_i = sum;
            if (sum < 0) sum = 0;
        }
        return max_i;
    }
    int kadaneMin(vector<int>& nums, int n) {
        int sum = 0, min_i = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum < min_i) min_i = sum;
            if (sum > 0) sum = 0;
        }
        return min_i;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int minSum = kadaneMin(nums, n);
        int maxSum = kadaneMax(nums, n);
        int circularSum = sum - minSum;
        if (maxSum > 0)
            return max(maxSum, circularSum);
        return maxSum;
    }
};