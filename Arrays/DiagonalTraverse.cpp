#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i = 0, j = 0;
        bool goingUp = true;
        vector<int> result;
        while (result.size() != m * n) {
            pair<int, int> p;
            if (goingUp) {
                while (i >= 0 && j < n) {
                    result.push_back(mat[i][j]);
                    p = {i, j};
                    i--;
                    j++;
                }
                goingUp = false;
                if (p.second + 1 < n) {
                    i = p.first;
                    j = p.second + 1;
                }
                else {
                    i = p.first + 1;
                    j = p.second;
                }
            }
            else {
                while (i < m && j >= 0) {
                    result.push_back(mat[i][j]);
                    p = {i, j};
                    i++;
                    j--;
                }
                goingUp = true;
                if (p.first + 1 < m) {
                    i = p.first + 1;
                    j = p.second;
                }
                else {
                    i = p.first;
                    j = p.second + 1;
                }
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    vector<int> ans = obj.findDiagonalOrder(mat);
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