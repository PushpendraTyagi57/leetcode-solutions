#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        int ramp = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (i < j && nums[i] > rightMax[j])
                i++;
            ramp = max(ramp, j - i);
            j++;
        }
        return ramp;
    }
};

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.maxWidthRamp(nums) << endl;
}