#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int north = 1, south = 0, east = 0, west = 0;
        set<pair<int, int>> obs;
        for (auto &o : obstacles)
            obs.insert({o[0], o[1]});
        pair<int, int> P{0,  0};
        int result = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (north) {
                if (commands[i] < 0) {
                    if (commands[i] == -1) {
                        east = 1;
                        north = 0;
                    }
                    else {
                        west = 1;
                        north = 0;
                    }
                }
                else {
                    int steps = commands[i];
                    while (steps--) {
                        pair<int, int> next = {P.first, P.second + 1};
                        if (obs.count(next)) break;
                        P = next;
                    }
                }
            }
            else if (south) {
                if (commands[i] < 0) {
                    if (commands[i] == -1) {
                        west = 1;
                        south = 0;
                    }
                    else {
                        east = 1;
                        south = 0;
                    }
                }
                else {
                    int steps = commands[i];
                    while (steps--) {
                        pair<int, int> next = {P.first, P.second - 1};
                        if (obs.count(next)) break;
                        P = next;
                    }
                }
            }
            else if (east) {
                if (commands[i] < 0) {
                    if (commands[i] == -1) {
                        south = 1;
                        east = 0;
                    }
                    else {
                        north = 1;
                        east = 0;
                    }
                }
                else {
                    int steps = commands[i];
                    while (steps--) {
                        pair<int, int> next = {P.first + 1, P.second};
                        if (obs.count(next)) break;
                        P = next;
                    }
                }
            }
            else {
                if (commands[i] < 0) {
                    if (commands[i] == -1) {
                        north = 1;
                        west = 0;
                    }
                    else {
                        south = 1;
                        west = 0;
                    }
                }
                else {
                    int steps = commands[i];
                    while (steps--) {
                        pair<int, int> next = {P.first - 1, P.second};
                        if (obs.count(next)) break;
                        P = next;
                    }
                }
            }
            result = max(result, P.first * P.first + P.second * P.second);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> commands(n);
    for (int i = 0; i < n; i++) cin >> commands[i];
    int m;
    cin >> m;
    vector<vector<int>> obstacles(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }
    }
    Solution obj;
    cout << obj.robotSim(commands, obstacles) << endl;
    return 0;
}