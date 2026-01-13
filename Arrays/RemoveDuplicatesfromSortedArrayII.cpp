class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto j : nums) {
            if (i == 0 || i == 1 || nums[i - 2] != j) {
                nums[i] = j;
                i++;
            }
        }
        return i;
    }
};