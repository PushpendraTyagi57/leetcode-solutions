#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count = 0;
        pair<int, int> p1 = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < p1.second) {
                count++;
                p1.second = min(p1.second, intervals[i][1]);
            }
            else
                p1 = {intervals[i][0], intervals[i][1]};
        }
        return count;
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
    cout << obj.eraseOverlapIntervals(intervals) << endl;
    return 0;
}