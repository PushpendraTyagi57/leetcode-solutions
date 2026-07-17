#include <bits/stdc++.h>

using namespace std;

int find(int i, vector<int> &parent)
{
    if (parent[i] == i)
        return parent[i];
    return parent[i] = find(parent[i], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);
    if (x_parent == y_parent)
        return;
    if (rank[x_parent] < rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else if (rank[x_parent] > rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else
    {
        parent[y_parent] = x_parent;
        rank[x_parent] += 1;
    }
}

bool equalNotEqual(string s)
{
    int n = s.size();
    vector<int> parent(n);
    vector<int> rank(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'E')
        {
            Union(i, (i + 1) % n, parent, rank);
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'N')
        {
            if (find(i, parent) == find((i + 1) % n, parent))
                return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string s;
        cin >> s;
        bool ans = equalNotEqual(s);
        cout << ((ans == 1) ? "YES" : "NO") << "\n";
    }
    return 0;
}