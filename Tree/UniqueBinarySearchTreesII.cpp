#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<TreeNode*> dp[9][9];
    vector<TreeNode*> solve(int start, int end) {
        if (start > end)    
            return {NULL};
        if (start == end) {
            TreeNode* newNode = new TreeNode(start);
            return {newNode};
        }
        if (!dp[start][end].empty()) return dp[start][end];
        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);
            for (TreeNode* leftRoot : left) {
                for (TreeNode* rightRoot : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.push_back(root);
                }
            }
        }
        return dp[start][end] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};

int main() {
    int n; cin >> n;
    Solution obj;
    vector<TreeNode*> result = obj.generateTrees(n);
    return 0;
}