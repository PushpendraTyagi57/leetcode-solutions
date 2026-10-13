#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            nums[i] = num;
        }
        sort(nums.begin(), nums.end());
        long long maxAltSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i >= n / 2) {
                maxAltSum += (nums[i] * nums[i]);
            }
            else {
                maxAltSum -= (nums[i] * nums[i]);
            }
        }
        return maxAltSum;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution* obj = new Solution();
    cout << obj->maxAlternatingSum(nums) << endl;
    return 0;
}