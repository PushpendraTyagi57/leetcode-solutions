#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> A, B;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) A.push_back({i, j});
                if (img2[i][j] == 1) B.push_back({i, j});
            }
        }
        map<pair<int, int>, int> mp;
        for (auto &p1 : A) {
            for (auto &p2 : B) {
                mp[{p2.first - p1.first, p2.second - p1.second}]++;
            }
        }
        int largestOverlap = 0;
        for (auto &it : mp)
            largestOverlap = max(largestOverlap, it.second);
        return largestOverlap;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> img1(n, vector<int>(n)), img2(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> img1[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> img2[i][j];
    Solution obj;
    cout << obj.largestOverlap(img1, img2) << endl;
    return 0;
}