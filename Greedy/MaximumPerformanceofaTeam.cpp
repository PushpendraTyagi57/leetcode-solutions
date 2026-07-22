#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> engineers;
        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        sort(engineers.rbegin(), engineers.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long currSpeed = 0;
        long long ans = 0;
        for (auto& engineer : engineers) {
            int speed = engineer[1];
            int efficiency = engineer[0];
            currSpeed += speed;
            pq.push(speed);
            if (pq.size() > k) {
                currSpeed -= pq.top();
                pq.pop();
            }
            ans = max(ans, currSpeed * efficiency);
        }
        return ans % MOD;
    }
};

int main() {
    int n; cin >> n;
    vector<int> speed(n), efficiency(n);
    for (int i = 0; i < n; i++) cin >> speed[i];
    for (int i = 0; i < n; i++) cin >> efficiency[i];
    int k; cin >> k;
    Solution obj;
    cout << obj.maxPerformance(n, speed, efficiency, k) << endl;
    return 0;
}