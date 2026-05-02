#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;
        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int x = que.front();
                que.pop();
                if (x == n - 1) return steps;
                if (x + 1 < n && !visited[x + 1]) {
                    visited[x + 1] = true;
                    que.push(x + 1);
                }
                if (x - 1 >= 0 && !visited[x - 1]) {
                    visited[x - 1] = true;
                    que.push(x - 1);
                }
                for (int idx : mp[arr[x]]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        que.push(idx);
                    }
                }
                mp[arr[x]].clear();
            }
            steps++;
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.minJumps(arr) << endl;
    return 0;
}