#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int& num : nums) mp[num]++;
        if (mp[n - 1] != 2) return false;
        for (int i = 1; i < n - 1; i++) {
            if (mp.find(i) != mp.end()) {
                if (mp[i] != 1) return false;
            }
            else return false;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    bool ans = obj.isGood(nums);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}