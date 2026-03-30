#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    vector<vector<int>> dp;
    int solve(vector<int>& stones, int currPosIdx, int lastJump) {
        if (currPosIdx == n - 1) return true;
        if (dp[currPosIdx][lastJump] != -1) return dp[currPosIdx][lastJump];
        bool result = false;
        for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++) {
            if (nextJump > 0) {
                int nextPos = stones[currPosIdx] + nextJump;
                if (mp.find(nextPos) != mp.end())
                    result = result || solve(stones, mp[nextPos], nextJump);
            }
        }
        return dp[currPosIdx][lastJump] = result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        if (stones[1] != 1) return false;
        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;
        return solve(stones, 0, 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[i];
    Solution obj;
    bool ans = obj.canCross(stones);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}