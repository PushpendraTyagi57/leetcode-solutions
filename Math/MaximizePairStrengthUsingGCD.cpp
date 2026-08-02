#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long ans = (1LL* nums[i] * nums[j]) / pow(__gcd(nums[i], nums[j]), 2);
                result = max(result, ans);
            }
        }
        return result;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.maxPairStrength(nums) << endl;
    return 0;
}