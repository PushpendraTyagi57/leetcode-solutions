#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> ms;
        int maxLen = 0;
        int i = 0, j = 0;
        while (j < n) {
            ms.insert(nums[j]);
            while (*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[i]));
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int limit;
    cin >> limit;
    Solution obj;
    cout << obj.longestSubarray(nums, limit) << endl;
    return 0;
}