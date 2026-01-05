class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k == 0) return operations;
        int i = 0;
        while (sum % k != 0) {
            nums[i] = nums[i] - 1;
            sum--;
            operations++;
        }
        return operations;
    }
};