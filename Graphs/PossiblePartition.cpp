#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i) {
        if (parent[i] == i) return parent[i];
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        unordered_map<int, vector<int>> adj;
        for (auto& dislike : dislikes) {
            int u = dislike[0];
            int v = dislike[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (adj[i].empty()) continue;
            int first = adj[i][0];
            for (int v = 1; v < adj[i].size(); v++) {
                if (find(i) == find(adj[i][v])) return false;
                Union(first, adj[i][v]);
            }
        }
        return true;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> dislikes(m, vector<int>(2));
    for (int i = 0; i < m; i++) cin >> dislikes[i][0] >> dislikes[i][1];
    Solution obj;
    cout << ((obj.possibleBipartition(n, dislikes)) ? "true" : "false") << endl;
    return 0;
}