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
        if (x_parent < y_parent) {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        parent.resize(26);
        rank.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int first = s1[i] - 'a';
            int second = s2[i] - 'a';
            Union(first, second);
        }
        string result = "";
        for (char ch : baseStr) {
            int parent = find(ch - 'a');
            result += char (parent + 'a');
        }
        return result;
    }
};

int main () {
    string s1, s2, baseStr;
    cin >> s1 >> s2 >> baseStr;
    Solution obj;
    cout << obj.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}