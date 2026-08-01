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
    int cameras;
    int minCamera(TreeNode* root) {
        if (root == NULL) return 1;
        int left = minCamera(root->left);
        int right = minCamera(root->right);
        if (left == -1 || right == -1) {
            cameras++;
            return 0;
        }
        if (left == 0 || right == 0) return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        if (minCamera(root) == -1) cameras++;
        return cameras;
    }
};