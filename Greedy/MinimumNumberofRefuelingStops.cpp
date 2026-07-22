#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int currFuel = startFuel;
        int stopsNeeded = 0;
        for (auto& station : stations) {
            int position = station[0];
            int fuel = station[1];
            while (currFuel < position) {
                if (pq.empty()) return -1;
                currFuel += pq.top();
                pq.pop();
                stopsNeeded++;
            }
            pq.push(fuel);
        }
        while (currFuel < target) {
            if (pq.empty()) return -1;
            currFuel += pq.top();
            pq.pop();
            stopsNeeded++;
        }
        return stopsNeeded;
    }
};

int main() {
    int target, startFuel;
    cin >> target >> startFuel;
    int n; cin >> n;
    vector<vector<int>> stations(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> stations[i][0] >> stations[i][1];
    }
    Solution obj;
    cout << obj.minRefuelStops(target, startFuel, stations) << endl;
    return 0;
}