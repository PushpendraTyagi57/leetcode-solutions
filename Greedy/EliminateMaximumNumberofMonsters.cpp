#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++)
            time[i] = ceil((float) dist[i] / speed[i]);
        sort(time.begin(), time.end());
        int timePassed = 1;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (time[i] - timePassed <= 0)
                return count;
            count++;
            timePassed++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> dist(n), speed(n);
    for (int i = 0; i < n; i++)
        cin >> dist[i] >> speed[i];
    Solution obj;
    cout << obj.eliminateMaximum(dist, speed) << endl;
    return 0;
}