#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getDigitSum(int num) {
        int result = 0;
        while (num > 0) {
            int rem = num % 10;
            result += rem;
            num /= 10;
        }
        return result;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int currSum = getDigitSum(nums[i]);
            minSum = min(minSum, currSum);
        }
        return minSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.minElement(nums) << endl;
    return 0;
}