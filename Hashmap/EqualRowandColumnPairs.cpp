#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>, int> mp;
        for (int row = 0; row < n; row++)
            mp[grid[row]]++;
        for (int c = 0; c < n; c++) {
            vector<int> temp;
            for (int r = 0; r < n; r++)
                temp.push_back(grid[r][c]);
            count += mp[temp];
        }   
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    Solution obj;
    cout << obj.equalPairs(grid) << endl;
    return 0;
}