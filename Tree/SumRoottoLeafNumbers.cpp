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
    int sum = 0;
    int num = 0;
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) sum += num;
        num = num * 10 + root->val;
        solve(root->left);
        solve(root->right);
        num = num / 10;
    }
    int sumNumbers(TreeNode* root) {
        solve(root);
        return sum;
    }
};