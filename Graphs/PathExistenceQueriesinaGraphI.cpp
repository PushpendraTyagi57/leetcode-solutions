#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, -1);
        int compId = 0;
        component[0] = compId;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                compId++;
            component[i] = compId;
        }

        vector<bool> result;
        for (auto& query : queries)
            result.push_back(component[query[0]] == component[query[1]]);
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int maxDiff; cin >> maxDiff;
    int q; cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<bool> result = obj.pathExistenceQueries(n, nums, maxDiff, queries);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << (result[i] ? "true" : "false");
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}