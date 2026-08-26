#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        unordered_map<int, vector<int>> redAdj;
        unordered_map<int, vector<int>> blueAdj;
        for (int i = 0; i < redEdges.size(); i++)
        {
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            redAdj[u].push_back(v);
        }
        for (int i = 0; i < blueEdges.size(); i++)
        {
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            blueAdj[u].push_back(v);
        }

        vector<int> dist(n, -1);
        dist[0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        visited[0][0] = true;
        visited[0][1] = true;

        queue<pair<int, pair<int, int>>> que;
        que.push({0, {0, 0}}); /* 0 -> Red, 1 -> Blue */
        que.push({0, {1, 0}});

        while (!que.empty())
        {
            auto [node, p] = que.front();
            int color = p.first;
            int currDist = p.second;
            que.pop();
            for (int neighbour : (color == 0 ? blueAdj[node] : redAdj[node]))
            {
                if (!visited[neighbour][1 - color])
                {
                    visited[neighbour][1 - color] = true;
                    if (dist[neighbour] == -1)
                        dist[neighbour] = currDist + 1;
                    que.push({neighbour, {1 - color, currDist + 1}});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<vector<int>> redEdges(x, vector<int>(2));
    for (int i = 0; i < x; i++)
    {
        cin >> redEdges[i][0] >> redEdges[i][1];
    }
    int y;
    cin >> y;
    vector<vector<int>> blueEdges(y, vector<int>(2));
    for (int i = 0; i < y; i++)
    {
        cin >> blueEdges[i][0] >> blueEdges[i][1];
    }
    Solution obj;
    vector<int> ans = obj.shortestAlternatingPaths(n, redEdges, blueEdges);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
        {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}