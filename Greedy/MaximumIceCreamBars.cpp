#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int bars = 0;
        for (int i = 0; i < n; i++) {
            if (coins == 0 || costs[i] > coins) break;
            else {
                bars++;
                coins -= costs[i];
            }
        }
        return bars;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; i++)
        cin >> costs[i];
    int coins;
    cin >> coins;
    Solution obj;
    cout << obj.maxIceCream(costs, coins);
    return 0;
}

