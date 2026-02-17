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
    int maxSum;
    int solve(TreeNode* root) {
        if (root == NULL)   
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int rootLeftRight = l + r + root->val;
        int maxLeftRight = max(l, r) + root->val;
        int onlyRoot = root->val;
        maxSum = max({maxSum, rootLeftRight, maxLeftRight, onlyRoot});
        return max(maxLeftRight, onlyRoot);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};