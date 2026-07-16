#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<long long, int> P;
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> adj;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> ways(n, 0);
        vector<long long> dist(n, 1e18);
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto it = pq.top();
            long long distance = it.first;
            int node = it.second;
            pq.pop();
            if (distance > dist[node]) continue;
            for (auto& neighbour : adj[node]) {
                int newNode = neighbour.first;
                int cost = neighbour.second;
                if (distance + cost < dist[newNode]) {
                    dist[newNode] = distance + cost;
                    ways[newNode] = ways[node];
                    pq.push({distance + cost, newNode});
                }
                else if (distance + cost == dist[newNode]) {
                    ways[newNode] = (ways[newNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> roads(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }
    Solution obj;
    cout << obj.countPaths(n, roads) << endl;
    return 0;
}