#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct trieNode {
        bool isEnd;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
                crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    
    int solve(int idx, string s) {
        if (idx == n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        ans = 1 + solve(idx + 1, s);
        trieNode* node = root;
        for (int i = idx; i < n; i++) {
            if (node->children[s[i] - 'a'] == NULL) break;
            node = node->children[s[i] - 'a'];
            if (node->isEnd) ans = min(ans, solve(i + 1, s));
        }
        return dp[idx] = ans;
    }
    int dp[51];
    trieNode* root;
    int n;

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        root = getNode();
        for (string& word : dictionary)
            insert(root, word);
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};