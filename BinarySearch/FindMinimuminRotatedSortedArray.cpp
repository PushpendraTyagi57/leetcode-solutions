class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum = INT_MAX;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
                minimum = min(minimum, nums[mid]);
            }
            else {
                high = mid - 1;
                minimum = min(minimum, nums[mid]);
            }
        }
        return minimum;
    }
};