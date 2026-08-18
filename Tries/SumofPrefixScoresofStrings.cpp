#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class trieNode {
    public:
        int count;
        trieNode* children[26];
        trieNode() {
            count = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    void insert(string& word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) crawler->children[idx] = new trieNode();
            crawler = crawler->children[idx]; 
            crawler->count++;
        }
    }

    int search(string& word) {
        trieNode* crawler = root;
        int score = 0;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            crawler = crawler->children[idx];
            score += crawler->count;
        }
        return score;
    }

    trieNode* root;
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new trieNode();
        int n = words.size();
        for (string word : words) {
            insert(word);
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            string word = words[i];
            answer[i] = search(word);
        }
        return answer;
    }
};

int main () {
    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    Solution obj;
    vector<int> ans = obj.sumPrefixScores(words);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}