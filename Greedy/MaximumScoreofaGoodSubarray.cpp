#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int currMin = nums[k];
        int result = nums[k];
        while (i > 0 || j < n - 1) {
            int leftVal = (i > 0) ? nums[i - 1] : 0;
            int rightVal = (j < n - 1) ? nums[j + 1] : 0;
            if (leftVal > rightVal) {
                i--;
                currMin = min(currMin, nums[i]);
            }
            else {
                j++;
                currMin = min(currMin, nums[j]);
            }
            result = max(result, currMin * (j - i + 1));
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maximumScore(nums, k) << endl;
    return 0;
}