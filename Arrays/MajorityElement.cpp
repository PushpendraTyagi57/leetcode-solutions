class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                curr = nums[i];
            }
            else if (curr == nums[i]) count++;
            else count--;
        }
        int count1 = 0;
        for (int i = 0; i < n; i++)
            if (curr == nums[i]) {
                count1++;
        }
        if (count1 > n / 2) return curr;
        return -1;
    }
};