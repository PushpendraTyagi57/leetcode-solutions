#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int i = 0, j = 0;
        int maxSize = 0;
        while (j < n) {
            if (nums[j] == 0) zeroCount++;
            while (zeroCount > 1) {
                if (nums[i] == 0) zeroCount--;
                i++;
            }
            maxSize = max(maxSize, j - i);
            j++;
        }
        return maxSize;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.longestSubarray(nums) << endl;
    return 0;
}