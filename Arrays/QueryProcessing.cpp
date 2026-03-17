#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long processQuery(int n, vector<int>& nums, int q, vector<vector<int>>& queries) {
            for (int i = 0; i < q; i++) {
                int l = queries[i][0], r = queries[i][1];
                int x = queries[i][2], y = queries[i][3];
                int t = 0;
                for (int j = l; j <= r; j++) {
                    nums[j] = x + t * y;
                    t++;
                }
            }
            long long sum = 0;
            for (int i = 0; i < n; i++)
                sum += nums[i];
            return sum;
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> queries[i][j];
        }
    }
    Solution obj;
    cout << obj.processQuery(n, nums, q, queries) << endl;
}