#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<string> result;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    struct trieNode {
        bool isEnd;
        string word;
        trieNode* children[26];
    };
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++)
            newNode->children[i] = NULL;
        return newNode;
    }
    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
                crawler->children[idx] = getNode();
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
        crawler->word = word;
    }
    void search(int i, int j, trieNode* root, vector<vector<char>>& board) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL)
            return;
        root = root->children[board[i][j] - 'a'];
        if (root->isEnd) {
            result.push_back(root->word);
            root->isEnd = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            search(new_i, new_j, root, board);
        }
        board[i][j] = temp; //backtracking
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        trieNode* root = getNode();
        for (string& word : words)
            insert(root, word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != NULL)
                    search(i, j, root, board);
            }
        }
        return result;
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<char>> board(x, vector<char>(y));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> board[i][j];
    int z;
    cin >> z;
    vector<string> words(z);
    for (int i = 0; i < z; i++)
        cin >> words[i];
    Solution obj;
    vector<string> ans = obj.findWords(board, words);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << "\"" << ans[i] << "\"";
            break;
        }
        cout << "\"" << ans[i] << "\"" << ", ";
    }
    cout << "]";
    return 0;
}