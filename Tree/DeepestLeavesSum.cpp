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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<int> lastLevel;
        while (!que.empty()) {
            int size = que.size();
            vector<int> traversal;
            while (size--) {
                auto curr = que.front();
                que.pop();
                traversal.push_back(curr->val);
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            if (que.empty()) {
                lastLevel = traversal;
                break;
            }
        }
        int result = 0;
        for (int num : lastLevel) result += num;
        return result;
    }
};