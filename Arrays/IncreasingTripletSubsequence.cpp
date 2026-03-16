#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int num1 = INT_MAX, num2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            int num3 = nums[i];
            if (num3 <= num1)
                num1 = num3;
            else if (num3 <= num2)
                num2 = num3;
            else
                return true;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    bool ans = obj.increasingTriplet(nums);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}