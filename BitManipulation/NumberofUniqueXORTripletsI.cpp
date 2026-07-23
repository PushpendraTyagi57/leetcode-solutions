#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2) return n;
        int ans = 1;
        while (ans <= n) {
            ans = (ans << 1);
        }
        return ans;
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