#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        if (deadend.count("0000")) return -1;
        unordered_set<string> visited;
        queue<string> que;
        que.push("0000");
        visited.insert("0000");
        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                string temp = que.front();
                que.pop();
                if (deadend.find(temp) != deadend.end()) continue;
                if (temp == target) return level;
                for (int i = 0; i < 4; i++) {
                    string up = temp;
                    up[i] = ((up[i] - '0' + 1) % 10) + '0';
                    if (!deadend.count(up) && !visited.count(up)) {
                        visited.insert(up);
                        que.push(up);
                    }
                    string down = temp;
                    down[i] = ((down[i] - '0' + 9) % 10) + '0';
                    if (!deadend.count(down) && !visited.count(down)) {
                        visited.insert(down);
                        que.push(down);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main() {
    int n; cin >> n;
    vector<string> deadends(n);
    for (int i = 0; i < n; i++) {
        cin >> deadends[i];
    }
    string target; cin >> target;
    Solution sol;
    cout << sol.openLock(deadends, target) << endl;
    return 0;
}