#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) return nums1[i];
            if (nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};

int main() {
    int m;
    cin >> m;
    vector<int> nums1(m);
    for (int i = 0; i < m; i++) cin >> nums1[i];
    int n;
    cin >> n;
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) cin >> nums2[i];
    Solution obj;
    cout << obj.getCommon(nums1, nums2) << endl;
    return 0;
}