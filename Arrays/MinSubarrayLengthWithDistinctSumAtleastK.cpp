class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(100001, 0);
        int i = 0;
        long long sum = 0;
        int minLength = INT_MAX;
        for (int j = 0; j < n; j++) {
            freq[nums[j]]++;
            if (freq[nums[j]] == 1) {
                sum += nums[j];
            }
            while (sum >= k) {
                minLength = min(minLength, j - i + 1);
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    sum -= nums[i];
                }
                i++;
            }
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};
