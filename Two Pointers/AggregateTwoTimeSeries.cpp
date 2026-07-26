#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int m = series1.size(), n = series2.size();
        vector<vector<int>> result;
        int i = 0, j = 0;
        unordered_set<int> usedTimestamp;
        while (i < m && j < n) {
            int timestamp = min(series1[i][0], series2[j][0]);
            int summedValue = series1[i][1] + series2[j][1];
            if (!usedTimestamp.count(timestamp)) result.push_back({timestamp, summedValue});
            if (series1[i][0] < series2[j][0]) {
                usedTimestamp.insert(series1[i][0]);
                i++;
            }
            else {
                usedTimestamp.insert(series2[j][0]);
                j++;
            }
        }
        while (i < m) {
            int timestamp = series1[i][0];
            int value = series1[i][1];
            if (!usedTimestamp.count(timestamp)) result.push_back({timestamp, value});
            i++;
        }
        while (j < n) {
            int timestamp = series2[j][0];
            int value = series2[j][1];
            if (!usedTimestamp.count(timestamp)) result.push_back({timestamp, value});
            j++;
        }
        return result;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> series1(m, vector<int>(2)), series2(n, vector<int>(2));
    for (int i = 0; i < m; i++) cin >> series1[i][0] >> series1[i][1];
    for (int i = 0; i < n; i++) cin >> series2[i][0] >> series2[i][1];
    Solution obj;
    vector<vector<int>> ans = obj.aggregateTimeSeries(series1, series2);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            cout << ans[i][j];
            if (j != 1) cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}