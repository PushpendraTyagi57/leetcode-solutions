#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(vector<int>& nums1, int target) {
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == target) continue;
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (nums1[i] - nums1[j] >= 1 && (nums1[i] - nums1[j]) % 2 == target) {
                    flag = true;
                    break;
                }
            }
            if (!flag) return false;
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        sort (nums1.begin(), nums1.end());
        return solve(nums1, 0) || solve(nums1, 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    Solution obj;
    bool ans = obj.uniformArray(nums1);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}