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
    void inOrder(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
    TreeNode* solve(int l, int r, vector<int>& result) {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(result[mid]);
        root->left = solve(l, mid - 1, result);
        root->right = solve(mid + 1, r, result);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> result;
        inOrder(root, result);
        int l = 0, r = result.size() - 1;
        return solve(l, r, result);

    }
};