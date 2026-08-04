#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_set<int> st;
        for (int num : nums) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            st.insert(num);
        }
        vector<int> ans;
        for (int i = minElement + 1; i < maxElement; i++) {
            if (!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.findMissingElements(nums);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i == ans.size() - 1) break;
        cout << ",";
    }
    cout << "]";
    return 0;
}