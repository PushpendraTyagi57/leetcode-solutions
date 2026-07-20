#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1);
        for (auto& booking : bookings) {
            int L = booking[0];
            int R = booking[1];
            int seats = booking[2];
            diff[L] += seats;
            if (R + 1 <= n) diff[R + 1] -= seats;
        }
        for (int i = 2; i <= n; i++) {
            diff[i] += diff[i - 1];
        }
        vector<int> answer;
        for (int i = 1; i <= n; i++) {
            answer.push_back(diff[i]);
        }
        return answer;
    }
};

int main() {
    int m; cin >> m;
    vector<vector<int>> bookings(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }
    int n; cin >> n;
    Solution obj;
    vector<int> ans = obj.corpFlightBookings(bookings, n);
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}