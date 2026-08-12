#include <bits/stdc++.h>

using namespace std;

class trieNode
{
public:
    bool isEnd;
    trieNode *children[3];
    trieNode()
    {
        isEnd = false;
        for (int i = 0; i < 3; i++)
        {
            children[i] = NULL;
        }
    }
};

class Solution
{
public:
    trieNode *root = new trieNode();
    bool dfs(trieNode *node, bool exactlyOneMismatch, string &word, int idx)
    {
        if (idx == word.size())
            return exactlyOneMismatch && node->isEnd;
        char ch = word[idx];
        int index = ch - 'a';
        if (node->children[index] != NULL)
        {
            trieNode *temp = node->children[index];
            if (dfs(temp, exactlyOneMismatch, word, idx + 1))
                return true;
        }
        if (!exactlyOneMismatch)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == index)
                    continue;
                if (node->children[i] != NULL)
                {
                    trieNode *temp = node->children[i];
                    if (dfs(temp, true, word, idx + 1))
                        return true;
                }
            }
        }
        return false;
    }
    void insert(string word)
    {
        trieNode *crawler = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
                crawler->children[idx] = new trieNode();
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    bool search(string word)
    {
        trieNode *curr = root;
        return dfs(curr, false, word, 0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Solution obj;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        obj.insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (obj.search(s))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}