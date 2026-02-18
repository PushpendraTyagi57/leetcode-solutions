class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int i = 0;
        long long maxSum = 0, currSum = 0;
        for (int j = 0; j < n; j++) {
            currSum += nums[j];
            freq[nums[j]]++;
            if (j - i + 1 > k) {
                currSum -= nums[i];
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++;
            }
            if (j - i + 1 == k && freq.size() == k)
                maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};