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
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            Union(u, v);
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            mp[root]++;
        }
        vector<int> count;
        for (auto& it : mp) count.push_back(it.second);
        long long answer = 0;
        int remaining = n;
        for (int i = 0; i < count.size(); i++) {
            answer += 1LL * (remaining - count[i]);
            remaining -= count[i];
        }
        return answer;
    }
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution obj;
    cout << obj.countPairs(n, edges) << endl;
    return 0;
}