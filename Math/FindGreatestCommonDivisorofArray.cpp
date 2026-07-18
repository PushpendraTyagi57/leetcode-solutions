#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minElement = INT_MAX, maxElement = INT_MIN;
        for (int& num : nums) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
        }
        return __gcd(minElement, maxElement);
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.findGCD(nums) << endl;
    return 0;
}