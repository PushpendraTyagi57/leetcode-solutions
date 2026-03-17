#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] >= 2) return true;
            }
            else
                mp[remainder] = i;
        }
        return false;
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
    bool ans = obj.checkSubarraySum(nums, k);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}