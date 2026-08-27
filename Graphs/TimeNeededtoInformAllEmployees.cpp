#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>> que;
        que.push({headID, 0});
        int ans = 0;
        while (!que.empty()) {
            auto [node, time] = que.front();
            que.pop();
            ans = max(ans, time);
            for (int neighbour : adj[node]) {
                que.push({neighbour, time + informTime[node]});
            }
        }
        return ans;
    }
};

int main () {
    int n; cin >> n;
    int headID; cin >> headID;
    vector<int> manager(n), informTime(n);
    for (int i = 0; i < n; i++) cin >> manager[i];
    for (int i = 0; i < n; i++) cin >> informTime[i];
    Solution obj;
    cout << obj.numOfMinutes(n, headID, manager, informTime) << endl;
    return 0;
}