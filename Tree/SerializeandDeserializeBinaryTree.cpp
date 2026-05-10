/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* temp = que.front();
                que.pop();
                if (temp == NULL) {
                    res += "null,";
                    continue;
                }
                res += to_string(temp->val) + ",";
                que.push(temp->left);
                que.push(temp->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            getline(ss, token, ',');
            if (token != "null") {
                TreeNode* leftNode = new TreeNode(stoi(token));
                curr->left = leftNode;
                que.push(leftNode);
            }
            getline(ss, token, ',');
            if (token != "null") {
                TreeNode* rightNode = new TreeNode(stoi(token));
                curr->right = rightNode;
                que.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));