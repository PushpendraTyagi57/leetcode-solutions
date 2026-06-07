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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> st;
        unordered_map<int, TreeNode*> connections;
        for (vector<int>& vec : descriptions) {
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];
            st.insert(child);
            if (connections.find(parent) == connections.end())
                connections[parent] = new TreeNode(parent);
            if (connections.find(child) == connections.end())
                connections[child] = new TreeNode(child);
            if (isLeft == 1) connections[parent]->left = connections[child];
            else connections[parent]->right = connections[child];
        }
        for (vector<int>& vec : descriptions) {
            int parent = vec[0];
            if (!st.count(parent)) return connections[parent];
        }
        return NULL;
    }
};