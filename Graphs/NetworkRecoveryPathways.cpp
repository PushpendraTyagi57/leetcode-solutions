#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<long long, int> P;
    typedef long long ll;
    bool check(int mid, int n, ll k, unordered_map<int, vector<vector<int>>>& adj) {
        vector<ll> result(n, LLONG_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        result[0] = 0;
        while (!pq.empty()) {
            ll dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dist > k) return false;
            if (u == n - 1) return true;
            if (result[u] < dist) continue;
            for (auto& neighbour : adj[u]) {
                int node = neighbour[0];
                int cost = neighbour[1];
                if (cost < mid) continue;
                if (dist + cost < result[node]) {
                    result[node] = dist + cost;
                    pq.push({result[node], node});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<int>& online, long long k) {
        int n = online.size();
        unordered_map<int, vector<vector<int>>> adj;
        int low = INT_MAX, high = 0;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (!online[u] || !online[v]) continue;
            adj[u].push_back({v, w});
            low = min(low, w);
            high = max(high, w);
        }
        int answer = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, k, adj)) {
                answer = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return answer;
    }
};

int main() {
    int m; cin >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int n; cin >> n;
    vector<int> online(n);
    for (int i = 0; i < n; i++) {
        cin >> online[i];
    }
    long long k; cin >> k;
    Solution sol;
    cout << sol.findMaxPathScore(edges, online, k) << endl;
    return 0;
}