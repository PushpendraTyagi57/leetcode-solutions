#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkFirstAndLastBlock(unordered_set<int>& st) {
        return (
            (!st.count(2) && !st.count(3) && !st.count(4) && !st.count(5)) &&
            (!st.count(6) && !st.count(7) && !st.count(8) && !st.count(9))
        );
    }

    bool checkAnyBlock(unordered_set<int>& st) {
        return (
            (!st.count(2) && !st.count(3) && !st.count(4) && !st.count(5)) ||
            (!st.count(4) && !st.count(5) && !st.count(6) && !st.count(7)) ||
            (!st.count(6) && !st.count(7) && !st.count(8) && !st.count(9))
        );
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto& seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }
        int count = 0;
        for (auto& it : mp) {
            unordered_set<int> st = it.second;
            if (checkFirstAndLastBlock(st)) {
                count += 2;
            }
            else if (checkAnyBlock(st)) count++;
        }
        count += 2 * (n - mp.size());
        return count;
    }
};

int main () {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> reservedSeats(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> reservedSeats[i][0] >> reservedSeats[i][1];
    }
    Solution obj;
    cout << obj.maxNumberOfFamilies(n, reservedSeats) << endl;
    return 0;
}