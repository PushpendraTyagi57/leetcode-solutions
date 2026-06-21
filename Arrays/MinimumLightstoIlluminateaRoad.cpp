#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (lights[i] == 0) continue;
            int L = max(0, i - lights[i]);
            int R = min(n - 1, i + lights[i]);
            arr[L] += 1;
            if (R + 1 < n) arr[R + 1] -= 1;
        }
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        int lightsNeeded = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) continue;
            int idx = min(n - 1, i + 1);
            arr[idx] = 1;
            if (idx + 1 < n) arr[idx + 1] = 1;
            if (idx - 1 >= 0) arr[idx - 1] = 1;
            lightsNeeded++;
        }
        return lightsNeeded;
    }
};

int main() {
    int n; cin >> n;
    vector<int> lights(n);
    for (int i = 0; i < n; i++)
        cin >> lights[i];
    Solution obj;
    cout << obj.minLights(lights) << endl;
    return 0;
}