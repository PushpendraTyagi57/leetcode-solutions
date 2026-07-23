#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> merge;
        for (int i = 0; i < n; i++) {
            merge.push_back({nums2[i], nums1[i]});
        }
        sort(merge.rbegin(), merge.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long currSum = 0;
        long long maxScore = 0;
        for (auto& elements : merge) {
            int num1 = elements[1];
            int num2 = elements[0];
            currSum += num1;
            pq.push(num1);
            while (pq.size() > k) {
                currSum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) maxScore = max(maxScore, currSum * 1LL * num2);
        }
        return maxScore;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    int k; cin >> k;
    Solution obj;
    cout << obj.maxScore(nums1, nums2, k) << endl;
    return 0;
}