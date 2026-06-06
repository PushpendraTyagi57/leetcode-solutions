#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            int left = currSum;
            currSum += nums[i];
            int right = totalSum - currSum;
            answer[i] = abs(left - right); 
        }
        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.leftRightDifference(nums);
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