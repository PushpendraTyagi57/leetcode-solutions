#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n);
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        vector<bool> suspicious(n);
        suspicious[k] = true;
        queue<int> que;
        que.push(k);

        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (int& neighbour : adj[curr]) {
                inDegree[neighbour]--;
                if (!suspicious[neighbour]) {
                    que.push(neighbour);
                    suspicious[neighbour] = true;
                }

            }
        }

        vector<int> result;
        bool isNotPossible = false;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && inDegree[i] != 0) {
                isNotPossible = true;
                break;
            }
            if (!suspicious[i]) result.push_back(i);
        }
        
        if (isNotPossible) {
            vector<int> vec(n);
            for (int i = 0; i < n; i++) vec[i] = i;
            return vec;
        }
        return result;
    }
};

int main () {
    int n, k;
    cin >> n >> k;
    int m; cin >> m;
    vector<vector<int>> invocations(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> invocations[i][j];
        }
    }
    Solution obj;
    vector<int> ans = obj.remainingMethods(n, k, invocations);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i == ans.size() - 1) break;
        cout << ",";
    }
    cout << "]";
    return 0;
}