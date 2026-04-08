#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            while (l <= r) {
                nums[l] = (1LL * nums[l] * v) % MOD;
                l += k;
            }
        }
            int result = 0;
            for (int &num : nums)
                result ^= num;
            return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(4));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> queries[i][j];
        }
    }
    Solution obj;
    cout << obj.xorAfterQueries(nums, queries) << endl;
    return 0;
}