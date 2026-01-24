class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minKPosition = -1;
        int maxKPosition = -1;
        int culpritIdx = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxK || nums[i] < minK) culpritIdx = i;
            if (nums[i] == minK) minKPosition = i;
            if (nums[i] == maxK) maxKPosition = i;
            long long smaller = min(minKPosition, maxKPosition);
            long long temp = smaller - culpritIdx;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};