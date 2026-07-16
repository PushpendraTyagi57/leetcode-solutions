#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int maxEffort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == m - 1 && col == n - 1) return maxEffort;
            if (maxEffort > dist[row][col]) continue;
            for (auto& dir : directions) {
                int new_i = row + dir[0];
                int new_j = col + dir[1];
                if (isValid(new_i, new_j, m, n)) {
                    int currEffort = abs(heights[new_i][new_j] - heights[row][col]);
                    int newEffort = max(maxEffort, currEffort);
                    if (newEffort < dist[new_i][new_j]) {
                        dist[new_i][new_j] = newEffort;
                        pq.push({newEffort, {new_i, new_j}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> heights(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heights[i][j];
        }
    }
    Solution obj;
    cout << obj.minimumEffortPath(heights) << endl;
    return 0;
}