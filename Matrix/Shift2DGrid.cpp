#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> answer;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                answer.push_back(grid[i][j]);
            }
        }
        k = k % answer.size();
        reverse(answer.begin(), answer.end());
        reverse(answer.begin(), answer.begin() + k);
        reverse(answer.begin() + k, answer.end());
        vector<vector<int>> result(m, vector<int>(n));
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = answer[idx++];
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int k; cin >> k;
    Solution obj;
    vector<vector<int>> ans = obj.shiftGrid(grid, k);
    cout << "[";
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
            if (j != n - 1) cout << ",";
        }
        cout << "]";
        if (i != m - 1) cout << ",";
    }
    cout << "]";
    return 0;
}