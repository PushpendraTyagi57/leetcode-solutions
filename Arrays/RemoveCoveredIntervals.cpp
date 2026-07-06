#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if (vec1[0] == vec2[0])
                return vec1[1] > vec2[1];
            return vec1[0] < vec2[0];
        };
        sort(intervals.begin(), intervals.end(), lambda);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int resultStart = result.back()[0];
            int resultEnd = result.back()[1];
            if (resultStart <= currStart && resultEnd >= currEnd) continue;
            result.push_back(intervals[i]);
        }
        return result.size();
    }
};

int main() {
    int m; cin >> m;
    vector<vector<int>> intervals(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution solution;
    cout << solution.removeCoveredIntervals(intervals) << endl;
    return 0;
}