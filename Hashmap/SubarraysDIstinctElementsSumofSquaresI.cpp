#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                count += (st.size()  * st.size());
            }
        }
        return count;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution* obj = new Solution();
    cout << obj->sumCounts(nums) << endl;
    return 0;
}