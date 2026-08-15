#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class trieNode {
    public:
        trieNode* left;
        trieNode* right;

        trieNode() {
            left = NULL;
            right = NULL;
        }
    };

    void insert(int& num) {
        trieNode* crawler = root;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 1) {
                if (crawler->right == NULL) crawler->right = new trieNode();
                crawler = crawler->right;
            }
            else {
                if (crawler->left == NULL) crawler->left = new trieNode();
                crawler = crawler->left;
            }
        }
    }

    int findMaxXor(int& num) {
        trieNode* crawler = root;
        int xorValue = 0;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 1) {
                if (crawler->left) {
                    xorValue += (1 << i);
                    crawler = crawler->left;
                }
                else {
                    crawler = crawler->right;
                }
            }
            else {
                if (crawler->right) {
                    xorValue += (1 << i);
                    crawler = crawler->right;
                }
                else {
                    crawler = crawler->left;
                }
            }
        }
        return xorValue;
    }

    trieNode* root; 
    int findMaximumXOR(vector<int>& nums) {
        root = new trieNode();
        for (int& num : nums) {
            insert(num);
        }
        int result = 0;
        for (int& num : nums) {
            int temp = findMaxXor(num);
            result = max(result, temp);
        }
        return result;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.findMaximumXOR(nums) << endl;
    return 0;
}