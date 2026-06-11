#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                exp -= 1;
                result = (result * base) % M;
            }
            else {
                exp /= 2;
                base = (base * base) % M;
            }
        }
        return result;
    }
    int findMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {
        int depth = 0;
        for (int& neighbour : adj[node]) {
            if (neighbour == parent) continue;
            depth = max(depth, findMaxDepth(adj, neighbour, node) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d = findMaxDepth(adj, 1, -1);
        return power(2, d - 1);
    }
};

int main() {
    int n; cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> edges[i][j];
        }
    }
    Solution obj;
    cout << obj.assignEdgeWeights(edges) << endl;
    return 0;
}