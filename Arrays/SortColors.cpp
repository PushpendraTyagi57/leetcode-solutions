#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zeroCount++;
            else if (nums[i] == 1) oneCount++;
            else twoCount++;
        }
        for (int i = 0; i < n; i++) {
            if (zeroCount) {
                nums[i] = 0;
                zeroCount--;
            }
            else if (oneCount) {
                nums[i] = 1;
                oneCount--;
            }
            else {
                nums[i] = 2;
                twoCount--;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    obj.sortColors(nums);
    return 0;
}