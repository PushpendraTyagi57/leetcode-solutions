#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDistance = INT_MIN;
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++)
                if (colors[i] != colors[j]) maxDistance = max(maxDistance, abs(i - j));
        return maxDistance;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> colors(n);
    for (int i = 0; i < n; i++) cin >> colors[i];
    Solution obj;
    cout << obj.maxDistance(colors) << endl;
    return 0;
}