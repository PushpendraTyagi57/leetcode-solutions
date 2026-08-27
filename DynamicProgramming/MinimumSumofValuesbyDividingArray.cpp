#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<unordered_map<int, int>>> dp;
    int solve(int i, int j, int andValue, vector<int>& nums, vector<int>& andValues) {
        if (i >= m) {
            if (j >= n) return 0;
            else return 1e9;
        }
        else if (j >= n) {
            return 1e9;
        }
        if (dp[i][j].count(andValue)) return dp[i][j][andValue];

        int take_i = 1e9;
        if ((andValue & nums[i]) == andValues[j]) {
            take_i = nums[i] + solve(i + 1, j + 1, (1 << 17) - 1, nums, andValues);
        }
        int skip_i = solve(i + 1, j, andValue & nums[i], nums, andValues);
        return dp[i][j][andValue] = min(take_i, skip_i);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        m = nums.size();
        n = andValues.size();
        dp.resize(m + 1, vector<unordered_map<int, int>>(11));
        int result = solve(0, 0, (1 << 17) - 1, nums, andValues);
        return result == 1e9 ? -1 : result;
    }
};

int main () {
    int x;
    cin >> x;
    vector<int> nums(x);
    for (int i = 0; i < x; i++) cin >> nums[i];
    int y;
    cin >> y;
    vector<int> andValues(y);
    for (int i = 0; i < y; i++) {
        cin >> andValues[i];
    }
    Solution obj;
    cout << obj.minimumValueSum(nums, andValues) << endl;
    return 0;
}