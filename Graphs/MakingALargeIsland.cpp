#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    int find(int i) {
        if (parent[i] == i) return parent[i];
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        parent.resize(n * n);
        rank.resize(n * n);
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (auto& direction : directions) {
                    int new_i = i + direction[0];
                    int new_j = j + direction[1];
                    if (isValid(new_i, new_j) && grid[new_i][new_j] == 1) {
                        int originalNode = i * n + j;
                        int currNode = new_i * n + new_j;
                        Union(originalNode, currNode);
                    }
                }
            }
        }
        unordered_map<int, int> componentSize;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int parentNode = find(i * n + j);
                componentSize[parentNode]++;
            }
        }

        int largestIsland = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                unordered_set<int> visited;
                for (auto& direction : directions) {
                    int new_i = i + direction[0];
                    int new_j = j + direction[1];
                    if (isValid(new_i, new_j) && grid[new_i][new_j] == 1) {
                        visited.insert(find(new_i * n + new_j));
                    }
                }
                int size = 0;
                for (auto& element : visited) size += componentSize[element];
                largestIsland = max(largestIsland, size + 1);
            }
        }

        for (int i = 0; i < n * n; i++) {
            largestIsland = max(largestIsland, componentSize[find(i)]);
        }
        return largestIsland;
    }
};

int main() {
    int m; cin >> m;
    vector<vector<int>> grid(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.largestIsland(grid) << endl;
    return 0;
}