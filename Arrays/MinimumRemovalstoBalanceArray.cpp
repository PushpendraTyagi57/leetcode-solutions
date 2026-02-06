class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int maxWindow = 1;
        while (j < n) {
            while (i < j && nums[j] > (long long)nums[i] * k)
                i++;
            maxWindow = max(maxWindow, j - i + 1);
            j++;
        }
        return n - maxWindow;

    }
};