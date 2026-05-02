#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) rem += k;
            if (mp.find(rem) != mp.end()) {
                result += mp[rem];
            }
            mp[rem]++;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.subarraysDivByK(nums, k) << endl;
    return 0;
}