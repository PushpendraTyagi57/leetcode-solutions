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
    void reverse(vector<int>& temp) {
        int start = 0, end = temp.size() - 1;
        while (start < end) {
            swap(temp[start++], temp[end--]);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;
        while (!que.empty()) {
            int size = que.size();
            vector<int> ds;
            while (size--) {
                TreeNode* temp = que.front();
                que.pop();
                ds.push_back(temp->val);
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            ans.push_back(ds);
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 1) reverse(ans[i]);
        }
        return ans;
    }
};