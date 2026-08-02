#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bs(vector<long long>& prefixSum, long long shift) {
        int low = 0, high = prefixSum.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (prefixSum[mid] <= shift) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = tasks[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + tasks[i];
        }
        vector<int> ans((int)shifts.size());
        long long shift = 0;
        for (int i = 0; i < shifts.size(); i++) {
            shift += shifts[i];
            ans[i] = n - bs(prefixSum, shift);
            if (ans[i] == 0) shift = 0;
        }
        return ans;
    }
};

int main () {
    int m, n;
    cin >> m >> n;
    vector<int> tasks(m), shifts(n);
    for (int i = 0; i < m; i++) cin >> tasks[i];
    for (int i = 0; i < n; i++) cin >> shifts[i];
    Solution obj;
    vector<int> ans = obj.countTasks(tasks, shifts);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i != n - 1) cout << ",";
    }
    cout << "]";
    return 0;
}