#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (result.empty() || intervals[i][0] > result.back()[1])
                result.push_back(intervals[i]);
            else
                result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> intervals[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> ans = obj.merge(intervals);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            if (j == 1) {
                cout << ans[i][j];
                break;
            }
            cout << ans[i][j] << ", ";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]";
    return 0;
}