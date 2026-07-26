#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max({nums[0] * nums[1] * nums[2], 
                    nums[n - 1] * nums[n - 2] * nums[n - 3],
                    nums[0] * nums[1] * nums[n - 1]});
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.maximumProduct(nums) << endl;
    return 0;
}