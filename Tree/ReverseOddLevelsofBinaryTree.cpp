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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool isOdd = false;
        while (!que.empty()) {
            int size = que.size();
            vector<TreeNode*> level;
            while (size--) {
                TreeNode* temp = que.front();
                que.pop();
                level.push_back(temp);
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            if (isOdd) {
                int i = 0, j = level.size() - 1;
                while (i < j) {
                    swap(level[i]->val, level[j]->val);
                    i++, j--;
                }
            }
            isOdd = !isOdd;
        }
        return root;
    }
};