#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1;
        for (int i = n - 1; i >= 2; i--) {
            if (sum - nums[i] > nums[i]) {
                ans = sum;
                break;
            }
            sum -= nums[i];
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    long long result = obj.largestPerimeter(nums);
    cout << result << endl;
    return 0;
}