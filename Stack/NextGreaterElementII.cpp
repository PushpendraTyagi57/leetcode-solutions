#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> NGE(n);
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) st.pop();
            if (i < n) {
                NGE[i] = (st.empty()) ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return NGE;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}