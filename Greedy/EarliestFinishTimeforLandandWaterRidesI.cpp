#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // land -> water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                int finish1 = waterStart + waterDuration[j];
                // water -> land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);
                int finish2 = landStart + landDuration[i];
                result = min({result, finish1, finish2});
            }
        }
        return result;
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