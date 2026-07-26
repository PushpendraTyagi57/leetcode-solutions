#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const long long INF = 1e18;
    vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, INF)));
        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1}); // cost, row, col, parity
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            long long currDist = node[0];
            int i = node[1];
            int j = node[2];
            int parity = node[3];
            if (currDist > dist[i][j][parity]) continue;
            if (i == m - 1 && j == n - 1) return currDist;
            long long waitCost = currDist + penalty[i][j];
            if (waitCost < dist[i][j][1 - parity]) {
                dist[i][j][1 - parity] = waitCost;
                pq.push({waitCost, i, j, 1 - parity});
            }
            for (int k = 0; k < directions.size(); k++) {
                int new_i = i + directions[k][0];
                int new_j = j + directions[k][1];
                if (!isValid(new_i, new_j, m, n)) continue;
                int currCost = (new_i + 1) * (new_j + 1);
                if (parity == 1 && (k == 2 || k == 3)) currCost += penalty[i][j];
                else if (parity == 0 && (k == 0 || k == 1)) currCost += penalty[i][j];
                if (currDist + currCost < dist[new_i][new_j][1 - parity]) {
                    dist[new_i][new_j][1 - parity] = currDist + currCost;
                    pq.push({dist[new_i][new_j][1 - parity], new_i, new_j, 1 - parity});
                }
            }
        }
        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> penalty(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> penalty[i][j];
        }
    }
    Solution obj;
    cout << obj.minCost(m, n, penalty) << endl;
    return 0;
}