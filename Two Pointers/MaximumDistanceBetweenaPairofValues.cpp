#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        int ans = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    Solution obj;
    cout << obj.maxDistance(nums1, nums2) << endl;
    return 0;
}