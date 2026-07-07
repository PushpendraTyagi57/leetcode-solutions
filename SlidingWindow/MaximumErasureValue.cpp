#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        vector<int> mp(10001, -1);
        int result = 0;
        int i = 0, j = 0;
        while (j < n) {
            i = max(i, mp[nums[j]] + 1);
            int right = prefixSum[j];
            int left = (i - 1 < 0 ? 0 : prefixSum[i - 1]);
            result = max(result, right - left);
            mp[nums[j]] = j;
            j++;
        }
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.maximumUniqueSubarray(nums) << endl;
    return 0;
}