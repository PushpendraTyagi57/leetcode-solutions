#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> solve(int k, vector<int>& nums) {
        int n = nums.size();
        if (k > n) return {};
        vector<int> num;
        num.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            while (!num.empty() && nums[i] > num.back() && num.size() + n - i > k) num.pop_back();
            num.push_back(nums[i]);
        }
        while (num.size() > k) num.pop_back();
        return num;
    }

    void merge(vector<int>& ans, vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] > nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] < nums2[j]) {
                ans.push_back(nums2[j]);
                j++;
            }
            else {
                int temp_i = i;
                int temp_j = j;
                while (temp_i < m && temp_j < n && nums1[temp_i] == nums2[temp_j]) {
                    temp_i++;
                    temp_j++;
                }
                if (temp_i == m) {
                    ans.push_back(nums2[j]);
                    j++;
                }
                else if (temp_j == n) {
                    ans.push_back(nums1[i]);
                    i++;
                }
                else if (nums1[temp_i] > nums2[temp_j]) {
                    ans.push_back(nums1[i]);
                    i++;
                }
                else {
                    ans.push_back(nums2[j]);
                    j++;
                }
            }
        }
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for (int i = 0; i <= k; i++) {
            vector<int> temp1 = solve(i, nums1);
            vector<int> temp2 = solve(k - i, nums2);
            vector<int> temp;
            merge(temp, temp1, temp2);
            if (temp.size() == k) ans = max(ans, temp);
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
    int k; cin >> k;
    Solution obj;
    vector<int> ans = obj.maxNumber(nums1, nums2, k);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}