#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 1) {
            int maxVal = -1;
            for (int& num : nums) {
                if (mp[num] == 1 && num > maxVal) maxVal = num;
            }
            return maxVal;
        }
        if (nums[0] == nums[n - 1]) return -1;
        if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) {
            return max(nums[0], nums[n - 1]);
        }
        if (mp[nums[0]] == 1 && mp[nums[n - 1]] > 1) return nums[0];
        if (mp[nums[0]] > 1 && mp[nums[n - 1]] == 1) return nums[n - 1];
        return -1; 
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k; cin >> k;
    Solution obj;
    cout << obj.largestInteger(nums, k) << endl;
    return 0;
}