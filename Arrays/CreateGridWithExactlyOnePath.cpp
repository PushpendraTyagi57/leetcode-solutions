#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for (int i = 0; i < n; i++) ans[0][i] = '.';
        for (int i = 0; i < m; i++) ans[i][n - 1] = '.';
        return ans;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    Solution obj;
    vector<string> ans = obj.createGrid(m, n);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << "\"" << ans[i] << "\"";
            break;
        }
        cout << "\"" << ans[i] << "\"" << ", ";
    }
    cout << "]";
}