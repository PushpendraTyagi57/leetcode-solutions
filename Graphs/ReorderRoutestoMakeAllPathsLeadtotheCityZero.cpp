#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int count = 0;
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (auto neighbour : adj[node]) {
                if (visited[neighbour.first]) continue;
                if (neighbour.second == 1) count++;
                visited[neighbour.first] = true;
                que.push(neighbour.first);
            }
        }
        return count;
    }
};

int main () {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }
    Solution obj;
    cout << obj.minReorder(n, connections) << endl;
    return 0;
}