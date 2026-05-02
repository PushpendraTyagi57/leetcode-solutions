#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {
                int j = i;
                while (j < n && nums[j] == 0) j++;
                int size = j - i;
                count += (1LL * size * (size + 1)) / 2;
                i = j;
                continue;
            }
            i++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.zeroFilledSubarray(nums) << endl;
    return 0;
}