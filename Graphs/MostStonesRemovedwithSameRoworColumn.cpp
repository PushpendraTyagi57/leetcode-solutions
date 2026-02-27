#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& stones, int idx, vector<bool>& visited) {
        visited[idx] = true;
        for (int i = 0; i < n; i++) {
            int r = stones[idx][0];
            int c = stones[idx][1];
            if ((visited[i] == false) && (stones[i][0] == r || stones[i][1] == c))
                dfs(stones, i, visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);
        int group = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            dfs(stones, i, visited);
            group++;
        }
        return n - group;
    }
};

int main () {
    int n;
    cin >> n;
    vector<vector<int>> stones(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> stones[i][0] >> stones[i][1];
    Solution obj;
    cout << obj.removeStones(stones);
    return 0;
}