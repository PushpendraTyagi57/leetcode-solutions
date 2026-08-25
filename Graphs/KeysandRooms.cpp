#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (int keys : rooms[node]) {
                if (!visited[keys]) {
                    visited[keys] = true;
                    que.push(keys);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};

int main () {
    int m;
    cin >> m;
    vector<vector<int>> rooms(m);
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        rooms[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> rooms[i][j];
        }
    }
    Solution obj;
    cout << ((obj.canVisitAllRooms(rooms)) ? "true" : "false") << endl;
    return 0;
}