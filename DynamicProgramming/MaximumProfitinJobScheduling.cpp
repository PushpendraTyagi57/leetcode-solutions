#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> jobs;
    vector<int> dp;
    int solve(int idx) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int target = jobs[idx][1];
        int low = idx + 1, high = n - 1;
        int nextIdx = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid][0] >= target) {
                nextIdx = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        int take = jobs[idx][2] + solve(nextIdx);
        int skip = solve(idx + 1);
        return dp[idx] = max(take, skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        for (int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        dp.resize(n, -1);
        return solve(0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), profit(n);
    for (int i = 0; i < n; i++) cin >> startTime[i];
    for (int i = 0; i < n; i++) cin >> endTime[i];
    for (int i = 0; i < n; i++) cin >> profit[i];
    Solution obj;
    cout << obj.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}