#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> adj;
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) que.push(i);
        }
        vector<bool> isSafe(n, false);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            isSafe[u] = true;
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) que.push(v);
            }
        }
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) answer.push_back(i);
        }
        return answer;
    }
};

int main () {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        graph[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    Solution obj;
    vector<int> answer = obj.eventualSafeNodes(graph);
    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        if (i == answer.size() - 1) {
            cout << answer[i];
            break;
        }
        cout << answer[i] << ",";
    }
    cout << "]";
    return 0;
}