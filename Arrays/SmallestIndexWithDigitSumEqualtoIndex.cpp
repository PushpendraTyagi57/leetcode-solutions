#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = digitSum(nums[i]);
            if (i == num) return i;
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
    Solution obj;
    cout << obj.smallestIndex(nums) << endl;
    return 0;
}