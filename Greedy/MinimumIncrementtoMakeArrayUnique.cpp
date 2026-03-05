#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            while (nums[i] == nums[i - 1] || nums[i] < nums[i - 1]) {
                nums[i] += 1;
                count++;
            }
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
    Solution obj;
    cout << obj.minIncrementForUnique(nums) << endl;
    return 0;
}