#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[prefixSum[i]]++;
            if (prefixSum[i] < k) continue;
            else if (prefixSum[i] == k) count++;
            else {
                int remaining = prefixSum[i] - k;
                if (mp.count(remaining)) count += mp[remaining];
            }
        }
        return count;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k; cin >> k;
    Solution obj;
    cout << obj.subarraySum(nums, k) << endl;
    return 0;
}