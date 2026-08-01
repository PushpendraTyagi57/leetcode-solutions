#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> segTree;
    void buildSegTree(int left, int right, int index, vector<int>& baskets) {
        if (left == right) {
            segTree[index] = baskets[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegTree(left, mid, 2 * index + 1, baskets);
        buildSegTree(mid + 1, right, 2 * index + 2, baskets);
        segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
    }
    bool RMQ(int left, int right, int index, int fruit) {
        if (segTree[index] < fruit) return false;
        if (left == right) {
            segTree[index] = -1;
            return true;
        }
        int mid = left + (right - left) / 2;
        bool placed = false;
        if (segTree[2 * index + 1] >= fruit) placed = RMQ(left, mid, 2 * index + 1, fruit);
        else placed = RMQ(mid + 1, right, 2 * index + 2, fruit);
        segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree.resize(4 * n);
        buildSegTree(0, n - 1, 0, baskets);
        int unplacedCount = 0;
        for (int& fruit : fruits) {
            if (RMQ(0, n - 1, 0, fruit) == false) {
                unplacedCount++;
            }
        }
        return unplacedCount;
    }
};

int main () {
    int n; cin >> n;
    vector<int> fruits(n), baskets(n);
    for (int i = 0; i < n; i++) cin >> fruits[i];
    for (int i = 0; i < n; i++) cin >> baskets[i];
    Solution obj;
    cout << obj.numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}