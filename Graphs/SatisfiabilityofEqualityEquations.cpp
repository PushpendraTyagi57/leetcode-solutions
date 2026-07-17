#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i) {
        if (parent[i] == i) return parent[i];
        return parent[i] = find(parent[i]);
    }
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for (string& s : equations) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }
        for (string& s : equations) {
            if (s[1] == '!') {
                char first = s[0];
                char second = s[3];
                int parentFirst = find(first - 'a');
                int parentSecond = find(second - 'a');
                if (parentFirst == parentSecond) return false;
            }
        }
        return true;
    }
};

int main() {
    int n; cin >> n;
    vector<string> equations(n);
    for (int i = 0; i < n; i++) cin >> equations[i];
    Solution obj;
    cout << ((obj.equationsPossible(equations) == 1) ? "true" : "false") << endl;
    return 0;
}