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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        int components = n;
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            int u_parent = find(u);
            int v_parent = find(v);
            if (u_parent == v_parent) continue;
            else {
                Union(u, v);
                components--;
            }
        }
        return components - 1;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }
    Solution obj;
    cout << obj.makeConnected(n, connections) << endl;
    return 0;
}