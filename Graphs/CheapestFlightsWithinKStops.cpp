#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<P>> adj;
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, P>> que;
        que.push({0, {src, 0}});
        dist[src] = 0;
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k) continue;
            for (auto& neighbour : adj[node]) {
                int v = neighbour.first;
                int currCost = neighbour.second;
                if (cost + currCost < dist[v] && stops <= k) {
                    dist[v] = cost + currCost;
                    que.push({stops + 1, {v, cost + currCost}});
                }
            }
        }
        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    int src, dest, k;
    cin >> src >> dest >> k;
    Solution obj;
    cout << obj.findCheapestPrice(n, flights, src, dest, k) << endl;
    return 0;
}