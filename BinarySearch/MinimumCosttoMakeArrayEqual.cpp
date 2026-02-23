#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, int target) {
        long long result = 0;
        for (int i = 0; i < nums.size(); i++)
            result += (long long) abs(nums[i] - target) * cost[i];
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer = LLONG_MAX;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid + 1);
            answer = min(cost1, cost2);
            if (cost1 > cost2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return answer;
    }
};

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    Solution obj;
    cout << obj.minCost(nums, cost) << endl;
    return 0;
}