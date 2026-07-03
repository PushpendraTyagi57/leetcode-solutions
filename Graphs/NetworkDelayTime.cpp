#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<P>> adj;
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            if (currDist > result[currNode]) continue;
            for (auto& neighbour : adj[currNode]) {
                int v = neighbour.first;
                int w = neighbour.second;
                if (currDist + w < result[v]) {
                    result[v] = currDist + w;
                    pq.push({currDist + w, v});
                }

            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX) return -1;
            ans = max(ans, result[i]);
        }
        return ans;
    }
};

int main() {
    int m;
    cin >> m;
    vector<vector<int>> times(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }
    int n, k;
    cin >> n >> k;
    Solution solution;
    cout << solution.networkDelayTime(times, n, k) << endl;
    return 0;
}