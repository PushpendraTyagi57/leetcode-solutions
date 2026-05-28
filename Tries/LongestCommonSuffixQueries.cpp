#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct trieNode {
        int idx;
        trieNode* children[26];

        trieNode(int i) {
            idx = i;
            for (int j = 0; j < 26; j++) {
                children[j] = NULL;
            }
        }

        ~trieNode() {
            for (int j = 0; j < 26; j++) {
                delete children[j];
            }
        }
    };

    void insertTrie(trieNode* root, int i, vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.size();
        for (int j = n - 1; j >= 0; j--) {
            char ch = word[j];
            int chIdx = ch - 'a';
            if (root->children[chIdx] == NULL) {
                root->children[chIdx] = new trieNode(i);
            }
            root = root->children[chIdx];
            if (wordsContainer[root->idx].size() > n) root->idx = i;
        }
    }

    int searchTrie(trieNode* root, string& word) {
        int resultIdx = root->idx;
        int n = word.size();
        for (int i = n - 1; i >= 0; i--) {
            int chIdx = word[i] - 'a';
            root = root->children[chIdx];
            if (root == NULL) return resultIdx;
            resultIdx = root->idx;
        }
        return resultIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size(), n = wordsQuery.size();
        vector<int> result(n);
        trieNode* root = new trieNode(0);

        for (int i = 0; i < m; i++) {
            int idx = root->idx;
            if (wordsContainer[idx].size() > wordsContainer[i].size()) root->idx = i;
            insertTrie(root, i, wordsContainer);
        }

        for(int i = 0; i < n; i++) {
            result[i] = searchTrie(root, wordsQuery[i]);
        }
        delete root;

        return result;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> wordsContainer(m);
    vector<string> wordsQuery(n);
    for (int i = 0; i < m; i++) cin >> wordsContainer[i];
    for (int i = 0; i < n; i++) cin >> wordsQuery[i];
    Solution obj;
    vector<int> ans = obj.stringIndices(wordsContainer, wordsQuery);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}