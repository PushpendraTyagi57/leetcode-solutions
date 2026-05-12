#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for (auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            if (mid < minimum) return false;
            mid -= actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int low = 0, high = 1e9;
        int result = INT_MAX;
        auto lambda = [](auto &task1, auto &task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];
            return diff1 > diff2;
        };
        sort(tasks.begin(), tasks.end(), lambda);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(tasks, mid)) {
                result = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> tasks[i][j];
    Solution obj;
    cout << obj.minimumEffort(tasks) << endl;
    return 0;
}