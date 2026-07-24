#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> uniqueTriplets;
        for (auto& xorPair : st) {
            for (auto& num : nums) {
                uniqueTriplets.insert(xorPair ^ num);
            }
        }
        return uniqueTriplets.size();
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.uniqueXorTriplets(nums) << endl;
    return 0;
}