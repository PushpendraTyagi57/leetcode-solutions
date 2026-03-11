#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int &num : nums) 
            mp[num]++;
        for (auto &it : mp) {
            int val = it.first;
            int freq = it.second;
            pq.push({freq, val});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    Solution obj;
    vector<int> ans = obj.topKFrequent(nums, k);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}