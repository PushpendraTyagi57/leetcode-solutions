#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<int> cost(n, 0);
        for (int i = 1; i < n - 1; i++) {
            int diff = max(nums[i - 1], nums[i + 1]) - nums[i] + 1;
            cost[i] = max(0, diff);
        }
        if (n % 2 == 1) {
            long long total = 0;
            for (int i = 1; i < n - 1; i += 2) {
                total += cost[i];
            }
            return total;
        }
        vector<long long> pre(n, 0), suf(n, 0);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1];
            if (i % 2 == 1 && i < n - 1)
                pre[i] += cost[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (i % 2 == 0 && i > 0)
                suf[i] += cost[i];
        }
        long long ans = LLONG_MAX;
        for (int i = 1; i < n - 1; i++) {
            long long left = pre[i - 1];
            long long right = suf[i + 1];
            ans = min(ans, left + right);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.minIncrease(nums) << endl;
    return 0;
}