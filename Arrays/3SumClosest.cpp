#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = 100000;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (abs(target - sum) < abs(target - closestSum))
                    closestSum = sum;
                if (sum < target) i++;
                else j--;
            }
        }
        return closestSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int target;
    cin >> target;
    Solution obj;
    cout << obj.threeSumClosest(nums, target) << endl;
    return 0;
}