#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int product = 1;
        int count = 0;
        while (j < n) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
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
    cout << obj.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}