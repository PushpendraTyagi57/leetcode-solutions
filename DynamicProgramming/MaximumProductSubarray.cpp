#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int n = nums.size();
        int maxProduct = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxProduct = max({maxProduct, prefix, suffix});
        }
        return maxProduct;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) 
        cin >> nums[i];
    Solution obj;
    cout << obj.maxProduct(nums) << endl;
    return 0;
}