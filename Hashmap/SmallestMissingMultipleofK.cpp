#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for (int num : nums) st.insert(num);
        for (int i = 1; i < 1000; i++) {
            if (!st.count(k * i)) return k * i;
        }
        return 0;
    }
};

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k; cin >> k;
    Solution obj;
    cout << obj.missingMultiple(nums, k) << endl;
    return 0;
}