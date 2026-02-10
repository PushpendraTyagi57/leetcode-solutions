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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> qu;
        vector<int> result;
        qu.push(root);
        while(!qu.empty()) {
            int n = qu.size();
            TreeNode* node = NULL;
            while (n--) {
                node = qu.front();
                qu.pop();
                if (node->left != NULL)
                    qu.push(node->left);
                if (node->right != NULL)
                    qu.push(node->right);
            }
            result.push_back(node->val);
        }
        return result;
    }
};