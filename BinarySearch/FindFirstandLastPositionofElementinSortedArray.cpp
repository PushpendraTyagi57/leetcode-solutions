class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int minRange = -1, maxRange = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) {
                minRange = mid;
                high = mid - 1;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) {
                maxRange = mid;
                low = mid + 1;
            }
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return {minRange, maxRange};
    }
};