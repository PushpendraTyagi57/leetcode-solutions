#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        set<pair<int, int>> visited;
        vector<vector<int>> result;
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visited.insert({0, 0});
        while (k-- && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    int k;
    cin >> k;
    Solution obj;
    vector<vector<int>> ans = obj.kSmallestPairs(nums1, nums2, k);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            if (j == 1) {
                cout << ans[i][j];
                break;
            }
            cout << ans[i][j] << ", ";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]";
    return 0;
}