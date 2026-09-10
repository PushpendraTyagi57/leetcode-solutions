#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int count;
    pair<int, int> solve(TreeNode* root) {
        if (!root) return make_pair(0, 0);

        auto leftSubTree = solve(root->left);
        auto rightSubTree = solve(root->right);

        int totalSum = root->val + leftSubTree.first + rightSubTree.first;
        int totalNodes = 1 + leftSubTree.second + rightSubTree.second;
        int average = floor(totalSum / totalNodes);
        
        if (average == root->val) count++;
        return make_pair(totalSum, totalNodes);
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        solve(root);
        return count;
    }
};

int main () {
    int n; cin >> n;
    vector<int> bfs(n);
    for (int i = 0; i < n; i++) cin >> bfs[i];
    if (n == 0 || bfs[0] == -1) return 0;
    TreeNode* root = new TreeNode(bfs[0]);
    queue<TreeNode*> que;
    que.push(root);
    int idx = 1;
    while (!que.empty() && idx < n) {
        TreeNode* curr = que.front();
        que.pop();
        if (idx < n && bfs[idx] != -1) {
            curr->left = new TreeNode(bfs[idx]);
            que.push(curr->left);
        }
        idx++;
        if (idx < n && bfs[idx] != -1) {
            curr->right = new TreeNode(bfs[idx]);
            que.push(curr->right);
        }
        idx++;
    }
    Solution* obj = new Solution();
    cout << obj->averageOfSubtree(root) << endl;
    return 0;
}