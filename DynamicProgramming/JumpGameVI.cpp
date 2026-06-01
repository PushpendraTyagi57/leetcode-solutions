#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> dp(n);
        dp[0] = nums[0];
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while (!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maxResult(nums, k) << endl;
    return 0;
}