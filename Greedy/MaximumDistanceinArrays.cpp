#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        int result = 0;
        for (int i = 1; i < n; i++) {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();
            result = max({result, abs(currMin - maxVal), abs(currMax - minVal)});
            minVal = min(minVal, currMin);
            maxVal = max(maxVal, currMax);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arrays(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        arrays[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> arrays[i][j];
    }
    Solution obj;
    cout << obj.maxDistance(arrays) << endl;
    return 0;
}