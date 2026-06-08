#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smaller, equal, larger;
        for (int& num : nums) {
            if (num < pivot) smaller.push_back(num);
            else if (num == pivot) equal.push_back(num);
            else larger.push_back(num);
        }
        int i = 0;
        for (int j = 0; j < smaller.size(); j++) {
            nums[i] = smaller[j];
            i++;
        }
        for (int j = 0; j < equal.size(); j++) {
            nums[i] = equal[j];
            i++;
        }
        for (int j = 0; j < larger.size(); j++) {
            nums[i] = larger[j];
            i++;
        }
        return nums;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int pivot; cin >> pivot;
    Solution obj;
    vector<int> ans = obj.pivotArray(nums, pivot);
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}