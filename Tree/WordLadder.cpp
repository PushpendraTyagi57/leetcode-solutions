#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        queue<string> qu;
        qu.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int level = 1;
        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                string word = qu.front();
                qu.pop();
                if (word == endWord) return level;
                for (int j = 0; j < word.size(); j++) {
                    string temp = word;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[j] = ch;
                        if (wordSet.find(temp) != wordSet.end() && visited.find(temp) == visited.end()) {
                            visited.insert(temp);
                            qu.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
        cin >> wordList[i];
    Solution obj;
    cout << obj.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}