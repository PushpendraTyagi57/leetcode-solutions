#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        deque<int> dq;
        int j = 0;
        int result = INT_MAX;
        while (j < n) {
            if (j == 0) prefixSum[j] = nums[j];
            else prefixSum[j] = prefixSum[j - 1] + nums[j];
            if (prefixSum[j] >= k) result = min(result, j + 1);

            while (!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k) {
                result = min(result, j - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefixSum[j] <= prefixSum[dq.back()]) dq.pop_back();
            dq.push_back(j);
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k; cin >> k;
    Solution obj;
    cout << obj.shortestSubarray(nums, k) << endl;
    return 0;
}