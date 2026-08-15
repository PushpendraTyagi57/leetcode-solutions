#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> up;
    int row, col;
    TreeAncestor(int n, vector<int>& parent) {
        row = n;
        col = log2(n) + 1;
        up.assign(row, vector<int>(col, -1));
        for (int node = 0; node < n; node++) {
            up[node][0] = parent[node];
        }

        for (int j = 1; j < col; j++) {
            for (int node = 0; node < row; node++) {
                if (up[node][j - 1] != -1) {
                    up[node][j] = up[up[node][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < col; j++) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */