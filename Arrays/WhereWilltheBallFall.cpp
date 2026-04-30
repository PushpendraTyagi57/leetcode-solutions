#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> answer(n);
        for (int col = 0; col < n; col++) {
            int i = 0, j = col;
            bool possible = true;
            while (i < m && j >= 0 && j < n) {
                if (grid[i][j] == 1) {
                    if (j == n - 1) {
                        possible = false;
                        break;
                    }
                    else if (j + 1 < n && grid[i][j + 1] == -1) {
                        possible = false;
                        break;
                    }
                    else {
                        i++;
                        j++;
                        continue;
                    }
                }
                else {
                    if (j == 0) {
                        possible = false;
                        break;
                    }
                    else if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        possible = false;
                        break;
                    }
                    else {
                        i++;
                        j--;
                        continue;
                    }
                }
            }
            if (possible) answer[col] = j;
            else answer[col] = -1;
        }
        return answer;
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
    Solution obj;
    vector<int> ans = obj.findBall(grid);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}