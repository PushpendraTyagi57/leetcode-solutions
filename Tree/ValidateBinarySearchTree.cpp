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
class Solution {
public:
    void helper(TreeNode* root, vector<int>& inOrder) {
        if (root == NULL)
            return;
        helper(root->left, inOrder);
        inOrder.push_back(root->val);
        helper(root->right, inOrder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        helper(root, inOrder);
        int isBST = true;
        int prev = inOrder[0];
        for (int i = 1; i < inOrder.size(); i++) {
            if (inOrder[i] <= prev)
                isBST = false;
            prev = inOrder[i];
        }
        return isBST;
    }
};