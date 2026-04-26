#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        if (total % 2 != 0) return false;
        long long upper = 0;
        for (int i = 0; i < m - 1; i++) {
            upper += rowSum[i];
            if (upper == total - upper) return true;
        }
        long long left = 0;
        for (int i = 0; i < n - 1; i++) {
            left += colSum[i];
            if (left == total - left) return true;
        }
        return false;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    Solution obj;
    bool ans = obj.canPartitionGrid(grid);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}