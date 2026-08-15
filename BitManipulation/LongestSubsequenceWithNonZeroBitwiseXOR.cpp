#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int allZero = true;
        for (int num : nums) {
            result = (result ^ num);
            if (num != 0) allZero = false;
        }
        if (allZero) return 0;
        return result == 0 ? n - 1 : n;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.longestSubsequence(nums) << endl;
    return 0;
}