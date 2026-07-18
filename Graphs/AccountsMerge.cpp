#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i)
    {
        if (parent[i] == i)
            return parent[i];
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);
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
            rank[x_parent]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        unordered_map<string, int> mailToName;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if (!mailToName.count(email))
                {
                    mailToName[email] = i;
                }
                else
                {
                    Union(i, mailToName[email]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for (auto &it : mailToName)
        {
            string email = it.first;
            int node = find(it.second);
            mergedMails[node].push_back(email);
        }
        vector<vector<string>> answer;
        for (int i = 0; i < n; i++)
        {
            if (mergedMails[i].size() == 0)
                continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &mail : mergedMails[i])
                temp.push_back(mail);
            answer.push_back(temp);
        }
        return answer;
    }
};
int main()
{
    int m;
    cin >> m;
    vector<vector<string>> accounts(m);
    for (int i = 0; i < m; i++)
    {
        int n; cin >> n;
        accounts[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> accounts[i][j];
        }
    }
    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    return 0;
}