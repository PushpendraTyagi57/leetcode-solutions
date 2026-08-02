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
    void solve(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>& mp) {
        if (root == NULL) return;
        mp[col].push_back({row, root->val});
        solve(root->left, row + 1, col - 1, mp);
        solve(root->right, row + 1, col + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        solve(root, 0, 0, mp);
        vector<vector<int>> answer;
        for (auto it : mp) {
            auto vec = it.second;
            sort(vec.begin(), vec.end());
            vector<int> curr;
            for (auto& num : vec) curr.push_back(num.second);
            answer.push_back(curr);
        }
        return answer;
    }
};