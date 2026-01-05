class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_i = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max_i) max_i = sum;
            if (sum < 0) sum = 0;
        }
        return max_i;
    }
};