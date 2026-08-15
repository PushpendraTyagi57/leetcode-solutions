#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class trieNode {
    public:
        bool isEnd;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->isEnd = false;
        return newNode;
    }

    void insert(string& word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }
    
    string getWord(string& word) {
        trieNode* crawler = root;
        string formWord = "";
        for (int i = 0; i < word.size(); i++) {
            if (crawler->isEnd) return formWord;
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) return word;
            formWord += ch;
            crawler = crawler->children[idx];
        }
        if (crawler->isEnd) return formWord;
        return word;
    }
    trieNode* root;
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = getNode();
        for (auto& word : dictionary) insert(word);
        string ans = "";
        int i = 0;
        while (i < sentence.size()) {
            string temp = "";
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ') {
                temp.push_back(sentence[j]);
                j++;
            }
            if (!ans.empty()) ans.push_back(' ');
            ans += getWord(temp);
            while (j < sentence.size() && sentence[j] == ' ') {
                j++;
            }
            i = j;
        }
        return ans;
    }
};

int main () {
    int n; cin >> n;
    vector<string> dictionary(n);
    for (int i = 0; i < n; i++) cin >> dictionary[i];
    cin.ignore();
    string sentence;
    getline(cin, sentence);
    Solution obj;
    cout << obj.replaceWords(dictionary, sentence);
    return 0;
}