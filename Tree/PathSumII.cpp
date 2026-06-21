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
    vector<vector<int>> result;
    void dfs(TreeNode* root, vector<int> arr, int currSum, int targetSum) {
        if (root == NULL) return;
        arr.push_back(root->val);
        currSum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (currSum == targetSum) result.push_back(arr);
            return;
        }
        dfs(root->left, arr, currSum, targetSum);
        dfs(root->right, arr, currSum, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return {};
        vector<int> arr;
        dfs(root, arr, 0, targetSum);
        return result;
    }
};