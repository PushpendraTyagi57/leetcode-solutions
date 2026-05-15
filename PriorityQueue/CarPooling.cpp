#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        for (auto& trip : trips) {
            int numPassengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            mp[start] += numPassengers;
            mp[end] -= numPassengers;
        }
        int currSeating = 0;
        for (auto& it : mp) {
            currSeating += it.second;
            if (currSeating > capacity) return false;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> trips(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> trips[i][j];
        }
    }
    int capacity;
    cin >> capacity;
    Solution obj;
    bool ans = obj.carPooling(trips, capacity);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}