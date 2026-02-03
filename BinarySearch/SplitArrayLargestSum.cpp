class Solution {
public:
    int countSplits(vector<int>& nums, int trialSplit) {
        int splits = 1;
        long long splitSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (splitSum + nums[i] <= trialSplit)
                splitSum += nums[i];
            else {
                splits += 1;
                splitSum = nums[i];
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int currentSplits = countSplits(nums, mid);
            if (currentSplits > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};