#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int farthest = 0;
        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            int start = max(farthest + 1, idx + minJump);
            int end = min(n - 1, idx + maxJump);
            for (int i = start; i <= end; i++) {
                if (s[i] == '0' && !visited[i]) {
                    if (i == n - 1) return true;
                    visited[i] = true;
                    que.push(i);
                }
            }
            farthest = max(farthest, end);
        }
        return n == 1;
    }

};

int main() {
    string s;
    cin >> s;
    int minJump, maxJump;
    cin >> minJump >> maxJump;
    Solution obj;
    bool ans = obj.canReach(s, minJump, maxJump);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}