#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int land = INT_MAX, water = INT_MAX;
        int land_water = INT_MAX, water_land = INT_MAX;
        for (int i = 0; i < n; i++)
            land = min(land, landStartTime[i] + landDuration[i]);
        for (int i = 0; i < m; i++) {
            water = min(water, waterStartTime[i] + waterDuration[i]);
            land_water = min(land_water, max(land, waterStartTime[i]) + waterDuration[i]);
        }
        for (int i = 0; i < n; i++)
            water_land = min(water_land, max(water, landStartTime[i]) + landDuration[i]);
        return min(land_water, water_land);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> landStartTime(n), landDuration(n);
    vector<int> waterStartTime(m), waterDuration(m);
    for (int i = 0; i < n; i++) {
        cin >> landStartTime[i] >> landDuration[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> waterStartTime[i] >> waterDuration[i];
    }
    Solution obj;
    cout << obj.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
    return 0;
}