class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i = -1, j = 0;
        int n = nums.size();
        while (j < n) {
            if (j + 1 < n && nums[j] >= nums[j + 1]) {
                i = j;
                j++;
                continue;
            }
            j++;
        }
        return (i == -1) ? 0 : i - 0 + 1;
    }
};