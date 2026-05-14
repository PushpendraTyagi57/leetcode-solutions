#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> ans;
        long long time = tasks[0][0];
        int i = 0;
        while (i < n || !pq.empty()) {
            while (i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2], tasks[i][0]});
                i++;
            }
            if (!pq.empty()) {
                int processingTime = pq.top()[0];
                time += processingTime;
                ans.push_back(pq.top()[1]);
                pq.pop();
            }
            else time = tasks[i][0];
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> tasks[i][j];
    Solution obj;
    vector<int> ans = obj.getOrder(tasks);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}