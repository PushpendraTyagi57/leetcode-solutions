#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if (n < 2 * k + 1)
            return result;
        long long window = 0;
        int left = 0, right = 2 * k;
        int i = k;
        for (int i = left; i <= right; i++)
            window += nums[i];
        int count = 2 * k + 1;
        result[i] = window / count;
        i++;
        right++;
        while (right < n) {
            int elementEntered = nums[right];
            int elementGone = nums[left];
            window = window + elementEntered - elementGone;
            result[i] = window / count;
            i++;
            right++;
            left++;
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
    vector<int> ans = obj.getAverages(nums, k);
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << ans[i];
            continue;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}