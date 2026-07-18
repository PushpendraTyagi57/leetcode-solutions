#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefixMax(n), prefixMin(n);
        prefixMax[0] = nums[0];
        prefixMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            prefixMin[i] = min(prefixMin[i - 1], nums[i]);
        }
        long long maxProduct = LLONG_MIN;
        for (int i = n - 1; i >= m - 1; i--) {
            maxProduct = max(maxProduct, 1LL * prefixMax[i - m + 1] * nums[i]);
            maxProduct = max(maxProduct, 1LL * prefixMin[i - m + 1] * nums[i]);
        }
        return maxProduct;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int m;
    cin >> m;
    Solution obj;
    cout << obj.maximumProduct(nums, m) << endl;
    return 0;
}