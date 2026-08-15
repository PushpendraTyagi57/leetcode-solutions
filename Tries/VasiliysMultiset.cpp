#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    class trieNode
    {
    public:
        trieNode *left;
        trieNode *right;
        int count;

        trieNode()
        {
            left = NULL;
            right = NULL;
            count = 0;
        }
    };

    void insert(int &num)
    {
        trieNode *crawler = root;
        for (int i = 30; i >= 0; i--)
        {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 1)
            {
                if (crawler->right == NULL)
                    crawler->right = new trieNode();
                crawler = crawler->right;
            }
            else
            {
                if (crawler->left == NULL)
                    crawler->left = new trieNode();
                crawler = crawler->left;
            }
            crawler->count++;
        }
    }

    void deleteOccurence(int &num)
    {
        trieNode *crawler = root;
        for (int i = 30; i >= 0; i--)
        {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 1)
            {
                crawler = crawler->right;
            }
            else
            {
                crawler = crawler->left;
            }
            crawler->count--;
        }
    }

    int findMaxXor(int &num)
    {
        trieNode *crawler = root;
        int xorValue = 0;
        for (int i = 30; i >= 0; i--)
        {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 1)
            {
                if (crawler->left && crawler->left->count > 0)
                {
                    xorValue += (1 << i);
                    crawler = crawler->left;
                }
                else
                {
                    crawler = crawler->right;
                }
            }
            else
            {
                if (crawler->right && crawler->right->count > 0)
                {
                    xorValue += (1 << i);
                    crawler = crawler->right;
                }
                else
                {
                    crawler = crawler->left;
                }
            }
        }
        return xorValue;
    }

    trieNode *root;
    void findMaximumXOR()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        root = new trieNode();
        int zero = 0;
        insert(zero);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            char ch;
            cin >> ch;
            int num;
            cin >> num;
            if (ch == '+')
                insert(num);
            else if (ch == '-')
                deleteOccurence(num);
            else
                cout << findMaxXor(num) << "\n";
        }
    }
};

int main()
{
    Solution obj;
    obj.findMaximumXOR();
    return 0;
}