#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int minCost = 0;
        int bought = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (bought == 2) {
                bought = 0;
                continue;
            }
            minCost += cost[i];
            bought++;
        }
        return minCost;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    Solution obj;
    cout << obj.minimumCost(cost) << endl;
    return 0;
}