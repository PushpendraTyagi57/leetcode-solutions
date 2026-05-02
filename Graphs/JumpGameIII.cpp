#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;
        int n = arr.size();
        queue<int> que;
        vector<bool> visited(n, false);
        visited[start] = true;
        que.push(start);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int x = que.front();
                que.pop();
                if (arr[x] == 0) return true;
                if (x + arr[x] < n && !visited[x + arr[x]]) {
                    visited[x + arr[x]] = true;
                    que.push(x + arr[x]);
                }
                if (x - arr[x] >= 0 && !visited[x - arr[x]]) {
                    visited[x - arr[x]] = true;
                    que.push(x - arr[x]);
                }
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int start;
    cin >> start;
    Solution obj;
    bool ans = obj.canReach(arr, start);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}