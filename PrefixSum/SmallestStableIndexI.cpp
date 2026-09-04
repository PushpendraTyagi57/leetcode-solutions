#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        int minElement = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            minElement = min(minElement, nums[i]);
            suffixMin[i] = minElement;
        }
        vector<int> prefixMax(n);
        int maxElement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxElement = max(maxElement, nums[i]);
            prefixMax[i] = maxElement;
        }
        for (int i = 0; i < n; i++) {
            if (prefixMax[i] - suffixMin[i] <= k) return i;
        }
        return -1;
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
    cout << obj.firstStableIndex(nums, k) << endl;
    return 0;
}