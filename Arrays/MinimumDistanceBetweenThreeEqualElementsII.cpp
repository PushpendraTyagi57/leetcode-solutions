#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;
        for (int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);
            if (mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];
                int size = vec.size();
                int i = vec[size - 3];
                result = min(result, 2 * (k - i));
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.minimumDistance(nums) << endl;
    return 0;
}