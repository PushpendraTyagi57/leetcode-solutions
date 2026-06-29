#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct trieNode {
        int endCount;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endCount = 0;
        for (int i = 0; i < 26; i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    void insert(string s) {
        trieNode* crawler = root;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
        }
        crawler->endCount++;
    }

    int search(string s, int idx) {
        trieNode* crawler = root;
        int ans = 0;
        for (int i = idx; i < s.size(); i++) {
            if (crawler->children[s[i] - 'a'] == NULL) break;
            crawler = crawler->children[s[i] - 'a'];
            if (crawler->endCount > 0) {
                ans += crawler->endCount;
                crawler->endCount = 0;
            }
        }
        return ans;
    }

    trieNode* root;
    int count;
    int numOfStrings(vector<string>& patterns, string word) {
        root = getNode();
        for (string& pattern : patterns)
            insert(pattern);
        count = 0;
        for (int i = 0; i < word.size(); i++) {
            count += search(word, i);
        }
        return count;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }
    string word;
    cin >> word;
    cout << obj.numOfStrings(patterns, word) << endl;
}