#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> mpLose;
        for (int i = 0; i < n; i++) {
            int loser = matches[i][1];
            mpLose[loser]++;
        }
        vector<int> ans0, ans1;
        unordered_set<int> added;
        for (int i = 0; i < n; i++) {
            int first = matches[i][0];
            int second = matches[i][1];
            if (!added.count(first)) {
                if (mpLose[first] == 0) ans0.push_back(first);
                else if (mpLose[first] == 1) ans1.push_back(first);
                added.insert(first);
            }
            if (!added.count(second)) {
                if (mpLose[second] == 0) ans0.push_back(second);
                else if (mpLose[second] == 1) ans1.push_back(second);
                added.insert(second);
            }
        }
        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        return {ans0, ans1};
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matches(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> matches[i][j];
    Solution obj;
    vector<vector<int>> result = obj.findWinners(matches);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            if (j == result[i].size() - 1) {
                cout << result[i][j];
                break;
            }
            cout << result[i][j] << ", ";
        }
        if (i == result.size() - 1) {
            cout << "]";
            break;
        }
        cout << "]" << ", ";
    }
    cout << "]";
    return 0;
}