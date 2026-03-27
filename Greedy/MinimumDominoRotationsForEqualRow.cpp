#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms, int val) {
        int swapTops = 0, swapBottoms = 0;
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val) return -1;
            else if (tops[i] != val) swapTops++;
            else if (bottoms[i] != val) swapBottoms++;
        }
        return min(swapTops, swapBottoms);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        for (int val = 1; val <= 6; val++) {
            int swaps = find(tops, bottoms, val);
            if (swaps != -1)
                result = min(result, swaps);
        }
        return (result == INT_MAX) ? -1 : result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> tops(n), bottoms(n);
    for (int i = 0; i < n; i++)
        cin >> tops[i];
    for (int i = 0; i < n; i++)
        cin >> bottoms[i];
    Solution obj;
    cout << obj.minDominoRotations(tops, bottoms) << endl;
    return 0;
}