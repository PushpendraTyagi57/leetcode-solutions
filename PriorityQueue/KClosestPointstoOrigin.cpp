#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> answer;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            int value = x * x + y * y;
            pq.push({value, x, y});
        }
        while (k--) {
            vector<int> vec = pq.top();
            pq.pop();
            int x = vec[1], y = vec[2];
            answer.push_back({x, y});
        }
        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> points[i][j];
    int k;
    cin >> k;
    Solution obj;
    vector<vector<int>> ans = obj.kClosest(points, k);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            if (j == 1) {
                cout << ans[i][j];
                break;
            }
            cout << ans[i][j] << ", ";
        }
        cout << "]";
    }
    cout << "]";
    return 0;
}