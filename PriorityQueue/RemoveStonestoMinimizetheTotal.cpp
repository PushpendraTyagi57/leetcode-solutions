#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
            pq.push(piles[i]);
        while (k--) {
            int removal = floor(pq.top() / 2);
            int remaining = pq.top() - removal;
            pq.pop();
            pq.push(remaining);
        }
        int result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        } 
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.minStoneSum(piles, k) << endl;
    return 0;
}