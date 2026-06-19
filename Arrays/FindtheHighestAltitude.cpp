#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int altitude = 0;
        for (int& num : gain) {
            altitude += num;
            maxAltitude = max(maxAltitude, altitude);
        }
        return maxAltitude;
    }
};

int main() {
    int n; cin >> n;
    vector<int> gain(n);
    for (int i = 0; i < n; i++) cin >> gain[i];
    Solution obj;
    cout << obj.largestAltitude(gain) << endl;
    return 0;
}