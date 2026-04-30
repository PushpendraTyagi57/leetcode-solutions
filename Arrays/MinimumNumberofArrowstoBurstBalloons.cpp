#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int count = 1;
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b) {
            return a[1] < b[1];
        });
        int lastRange = points[0][1]; 
        for (int i = 1; i < n; i++) {
            if (points[i][0] > lastRange) {
                count++;
                lastRange = points[i][1];
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> points[i][j];
        }
    }
    Solution obj;
    cout << obj.findMinArrowShots(points) << endl;
    return 0;
}