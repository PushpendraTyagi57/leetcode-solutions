#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) return -1;
        totalGas = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            totalGas = (totalGas + gas[i] - cost[i]);
            if (totalGas < 0) {
                totalGas = 0;
                result = i + 1;
            }
        }
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    Solution obj;
    cout << obj.canCompleteCircuit(gas, cost) << endl;
    return 0;
}