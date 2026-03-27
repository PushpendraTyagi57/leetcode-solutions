#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeroCount1 = 0, zeroCount2 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) zeroCount1++;
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) zeroCount2++;
            sum2 += nums2[i];
        }
        sum1 += zeroCount1;
        sum2 += zeroCount2;
        if (sum1 < sum2 && zeroCount1 == 0) return -1;
        if (sum1 > sum2 && zeroCount2 == 0) return -1;
        return max(sum1, sum2);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    int m;
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
        cin >> nums2[i];
    Solution obj;
    cout << obj.minSum(nums1, nums2) << endl;
    return 0;
}