#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> result;
    void solve(int node, vector<int>& ds, unordered_map<int, vector<int>>& adj) {
        if (node == n - 1) {
            result.push_back(ds);
            return;
        }
        for (int neighbour : adj[node]) {
            ds.push_back(neighbour);
            solve(neighbour, ds, adj);
            ds.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> ds;
        ds.push_back(0);
        solve(0, ds, adj);
        return result;
    }
};

int main () {
    int m; cin >> m;
    vector<vector<int>> graph(m);
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        graph[i].resize(p);
        for (int j = 0; j < p; j++) {
            cin >> graph[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> ans = obj.allPathsSourceTarget(graph);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            if (j == ans[i].size() - 1) {
                cout << ans[i][j];
                break;
            }
            cout << ans[i][j] << ",";
        }
        if (i == ans.size() - 1) {
            cout << "]";
            break;
        }
        cout << "],";
    }
    cout << "]";
}