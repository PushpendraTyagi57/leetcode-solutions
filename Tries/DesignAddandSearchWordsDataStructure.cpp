#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
public:
    struct trieNode {
        bool isEnd;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    void insert(trieNode* root, string word) {
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (root->children[idx] == NULL) root->children[idx] = getNode();
            root = root->children[idx];
        }
        root->isEnd = true;
    }

    bool searchWord(trieNode* root, string word, int idx) {
        if (idx == word.size())
            return root->isEnd;
        if (word[idx] != '.') {
            char ch = word[idx];
            if (root->children[ch - 'a'] == NULL) return false;
            return searchWord(root->children[ch - 'a'], word, idx + 1);
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i] && searchWord(root->children[i], word, idx + 1))
                return true;
        }
        return false;
    }

    trieNode* root;

    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */