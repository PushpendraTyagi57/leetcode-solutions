#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int count = 0;
        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
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
    cout << obj.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}