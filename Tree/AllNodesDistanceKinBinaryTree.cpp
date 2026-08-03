/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) parent[root->left] = root;
        inOrder(root->left);
        if (root->right != NULL) parent[root->right] = root;
        inOrder(root->right);
    }
    void bfs(TreeNode* root, TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> que;
        unordered_set<int> visited;
        que.push(target);
        visited.insert(target->val);
        while (!que.empty()) {
            int size = que.size();
            if (k == 0) break;
            while (size--) {
                TreeNode* curr = que.front();
                que.pop();
                if (curr->left != NULL && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if (curr->right != NULL && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if (parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while (!que.empty()) {
            result.push_back(que.front()->val);
            que.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inOrder(root);
        vector<int> result;
        bfs(root, target, k, result);
        return result;
    }
};