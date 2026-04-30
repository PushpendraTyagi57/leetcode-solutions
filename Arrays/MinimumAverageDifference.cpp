#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int minAvg = INT_MAX, smallestIdx = -1;
        for (int i = 0; i < n; i++) {
            long long firstAverage = prefixSum[i] / (i + 1);
            int lastAverage = 0;
            if (i != n - 1) lastAverage = (prefixSum[n - 1] - prefixSum[i]) / (n - i - 1);
            long long difference = abs(firstAverage - lastAverage);
            if (difference < minAvg) {
                minAvg = difference;
                smallestIdx = i;
            }
        }
        return smallestIdx;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.minimumAverageDifference(nums) << endl;
    return 0;
}