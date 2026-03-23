#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++)
            vec[i] = {nums1[i], nums2[i]};
        auto lambda = [&](auto &P1, auto &P2) {
            return P1.second > P2.second;
        };
        sort(vec.begin(), vec.end(), lambda);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long kSum = 0;
        for (int i = 0; i <= k - 1; i++) {
            kSum += vec[i].first;
            pq.push(vec[i].first);
        }
        long long result = kSum * vec[k - 1].second;
        for (int i = k; i < n; i++) {
            kSum += vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);
            result = max(result, kSum * vec[i].second);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    vector<int> nums2(n);
    for (int i = 0; i < n; i++)
        cin >> nums2[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maxScore(nums1, nums2, k) << endl;
    return 0;
}