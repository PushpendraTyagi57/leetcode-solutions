#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> availableSpace(n);
        for (int i = 0; i < n; i++)
            availableSpace[i] = capacity[i] - rocks[i];
        sort(availableSpace.begin(), availableSpace.end());
        int bagsFilled = 0;
        int i = 0;
        while (additionalRocks > 0 && i < n) {
            if (availableSpace[i] > additionalRocks) break;
            else if (additionalRocks >= availableSpace[i]) {
                additionalRocks -= availableSpace[i];
                bagsFilled++;
                i++;
            }
        }
        return bagsFilled;
    }
};

int main () {
    int n;
    cin >> n;
    vector<int> capacity(n), rocks(n);
    for (int i = 0; i < n; i++)
        cin >> capacity[i] >> rocks[i];
    int additionalRocks;
    cin >> additionalRocks;
    Solution obj;
    cout << obj.maximumBags(capacity, rocks, additionalRocks);
    return 0;
}