#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    typedef pair<long long, int> P;
    vector<int> shortestPath(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<P>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int dist = edge[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> dist(n + 1, LLONG_MAX);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (distance > dist[node])
                continue;
            for (auto &neighbour : adj[node])
            {
                int currNode = neighbour.first;
                int cost = neighbour.second;
                if (distance + cost < dist[currNode])
                {
                    dist[currNode] = distance + cost;
                    parent[currNode] = node;
                    pq.push({dist[currNode], currNode});
                }
            }
        }
        if (dist[n] == LLONG_MAX)
            return {};
        vector<int> ans;
        int node = n;
        while (parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    Solution obj;
    vector<int> ans = obj.shortestPath(n, edges);
    if (ans.empty())
    {
        cout << -1;
    }
    else
    {
        for (int num : ans)
            cout << num << " ";
    }
}