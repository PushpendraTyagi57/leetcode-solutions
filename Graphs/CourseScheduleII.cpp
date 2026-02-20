class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& inDegree, vector<int>& result) {
        queue<int> que;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            result.push_back(u);
            for (int &v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }
        if (n == count)
            return result;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        return topologicalSort(adj, numCourses, inDegree, result);
    }
};