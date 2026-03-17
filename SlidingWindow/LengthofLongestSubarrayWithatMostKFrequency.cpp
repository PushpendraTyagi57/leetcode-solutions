#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int longestSubarray = 0;
        while (j < n) {
            mp[nums[j]]++;
            while (mp[nums[j]] > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            longestSubarray = max(longestSubarray, j - i + 1);
            j++;
        }
        return longestSubarray;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maxSubarrayLength(nums, k) << endl;
    return 0;
}