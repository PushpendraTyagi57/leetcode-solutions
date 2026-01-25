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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> result;
        if (root == NULL) return result;
        qu.push(root);

        while (!qu.empty()) {
            int sz = qu.size();
            vector<int> level;

            while (sz--) {
                TreeNode* treeNode = qu.front();
                qu.pop();
                level.push_back(treeNode->val);
                if (treeNode->left != NULL) qu.push(treeNode->left);
                if (treeNode->right != NULL) qu.push(treeNode->right);
            }

            result.push_back(level);
        }
        return result;
    }
};