/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int lastVal;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* temp = que.front();
                que.pop();
                if (temp->right) que.push(temp->right);
                if (temp->left) que.push(temp->left);
                lastVal = temp->val;
            }
        }
        return lastVal;
    }
};