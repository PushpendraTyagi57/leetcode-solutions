#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = INT_MIN, minElement = INT_MAX;
        for (int& num : nums) {
            maxElement = max(maxElement, num);
            minElement = min(minElement, num);
        }
        long long val = maxElement - minElement;
        return (long long) k * val;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k; cin >> k;
    Solution obj;
    cout << obj.maxTotalValue(nums, k) << endl;
    return 0;
}