#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(n), minRight(n);
        maxLeft[0] = nums[0];
        minRight[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) maxLeft[i] = max(nums[i], maxLeft[i - 1]);
        for (int i = n - 2; i >= 0; i--) minRight[i] = min(nums[i], minRight[i + 1]);
        vector<int> ans(n);
        ans[n - 1] = maxLeft[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (maxLeft[i] <= minRight[i + 1]) ans[i] = maxLeft[i];
            else ans[i] = ans[i + 1];
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.maxValue(nums);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}