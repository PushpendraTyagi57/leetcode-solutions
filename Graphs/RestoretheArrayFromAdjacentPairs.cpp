#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> result;
    void dfs(int u, int prev, unordered_map<int, vector<int>>& adj) {
        result.push_back(u);
        for (int &v : adj[u]) {
            if (v != prev)
                dfs(v, u, adj);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> &vec : adjacentPairs) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int startPoint = -1;
        for (auto &it : adj) {
            if (it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }
        dfs(startPoint, INT_MIN, adj);
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjacentPairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> adjacentPairs[i][j];
    Solution obj;
    vector<int> ans = obj.restoreArray(adjacentPairs);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}