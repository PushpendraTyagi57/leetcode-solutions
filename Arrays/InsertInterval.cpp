#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> result;
        if (n == 0) {
            result.push_back(newInterval);
            return result;
        }
        while (i < n) {
            while (i < n && intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
                i += 1;
            }
            while (i < n && intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i += 1;
            }
            result.push_back(newInterval);
            while (i < n) {
                result.push_back(intervals[i]);
                i += 1;
            }
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> intervals[i][j];
    vector<int> newInterval(2);
    for (int i = 0; i < 2; i++)
        cin >> newInterval[i];
    Solution obj;
    vector<vector<int>> ans = obj.insert(intervals, newInterval);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            if (j == 1) {
                cout << intervals[i][j];
                break;
            }
            cout << intervals[i][j] << ", ";
        }
        if (i == ans.size() - 1) {
            cout << "]";
            break;
        }
        cout << "], ";
    }
    cout << "]";
    return 0;
}