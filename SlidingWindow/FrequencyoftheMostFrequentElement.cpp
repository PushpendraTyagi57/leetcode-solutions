#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        long currSum = 0;
        int result = 0;
        for (int r = 0; r < n; r++) {
            long target = nums[r];
            currSum += nums[r];
            if ((r - l + 1) * target - currSum > k) {
                currSum -= nums[l];
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
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
    cout << obj.maxFrequency(nums, k) << endl;
    return 0;
}