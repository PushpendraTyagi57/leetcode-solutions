#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastDay;
    vector<int> dp;
    int solve(int day, vector<int>& costs, vector<bool>& travel) {
        if (day > lastDay) return 0;
        if (dp[day] != -1) return dp[day];
        if (!travel[day]) return solve(day + 1, costs, travel);
        return dp[day] = min({costs[0] + solve(day + 1, costs, travel), 
                    costs[1] + solve(day + 7, costs, travel),
                    costs[2] + solve(day + 30, costs, travel)});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        lastDay = days.back();
        vector<bool> travel(lastDay + 1, false);
        for (int day : days) {
            travel[day] = true;
        }
        dp.assign(lastDay + 1, -1);
        return solve(1, costs, travel);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    vector<int> costs(3);
    for (int i = 0; i < 3; i++) {
        cin >> costs[i];
    }
    Solution* obj = new Solution();
    cout << obj->mincostTickets(days, costs) << endl;
    return 0;
}