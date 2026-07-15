#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, unordered_set<int>>& adj) {
        vector<int> inDegree(26, 0);
        for (int u = 0; u < 26; u++) {
            for (auto& neighbour : adj[u]) {
                inDegree[neighbour]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] == 0) que.push(i);
        }
        vector<int> topo;
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            topo.push_back(node);
            for (auto& neighbour : adj[node]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) que.push(neighbour);
            }
        }
        return topo;

    }
    string findOrder(vector<string>& words) {
        unordered_map<int, unordered_set<int>> adj;
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            bool found = false;
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].insert(s2[j] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && s1.size() > s2.size()) return "";
        }
        vector<int> topo = topologicalSort(adj);
        if (topo.size() != 26) return "";
        string order;
        for (int& num : topo) order += char(num + 'a');
        return order;
    }
};
int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    Solution obj;
    string order = obj.findOrder(words);
    cout << ((order.empty()) ? "Impossible" : order) << endl;

}