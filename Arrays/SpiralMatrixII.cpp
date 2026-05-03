#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, down = n - 1, left = 0, right = n - 1;
        int id = 0;
        int counter = 1;
        while (top <= down && left <= right) {
            if (id == 0) {
                for (int i = left; i <= right; i++) {
                    ans[top][i] = counter++;
                }
                top++;
            }
            if (id == 1) {
                for (int i = top; i <= down; i++) {
                    ans[i][right] = counter++;
                }
                right--;
            }
            if (id == 2) {
                for (int i = right; i >= left; i--) {
                    ans[down][i] = counter++;
                }
                down--;
            }
            if (id == 3) {
                for (int i = down; i >= top; i--) {
                    ans[i][left] = counter++;
                }
                left++;
            }
            id = (id + 1) % 4;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Solution obj;
    vector<vector<int>> result = obj.generateMatrix(n);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                cout << result[i][j] << "]";
                if (i != n - 1) cout << ", ";
                break;
            }
            cout << result[i][j] << ", ";
        }
    }
    cout << "]";
    return 0;
}