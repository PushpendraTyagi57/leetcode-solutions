#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    void dfs(int u, int& result, unordered_map<int, vector<P>>& adj, vector<bool>& visited, vector<vector<int>>& roads) {
        visited[u] = true;
        for (auto& neighbour : adj[u]) {
            int v = neighbour.first;
            int dist = neighbour.second;
            result = min(result, dist);
            if (!visited[v]) {
                dfs(v, result, adj, visited, roads);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> adj;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        vector<bool> visited(n + 1, false);
        int result = INT_MAX;
        dfs(1, result, adj, visited, roads);
        return result;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> roads(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        roads[i] = {u, v, dist};
    }
    Solution solution;
    cout << solution.minScore(n, roads) << endl;
    return 0;
}