class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                sum += (long long)nums[j];
                if (st.find(sum) != st.end()) ans++;
            }
        }
        return ans;
    }
};