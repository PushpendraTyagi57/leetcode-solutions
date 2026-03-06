#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        long maxReach = 0;
        int i = 0;
        while (maxReach < n) {
            if (i < nums.size() && nums[i] <= maxReach + 1) {
                maxReach += nums[i];
                i++;
            }
            else {
                maxReach += (maxReach + 1);
                patch++;
            }
        }
        return patch;
    }
};

int main() {
    int k;
    cin >> k;
    vector<int> nums(k);
    for (int i = 0; i < k; i++)
        cin >> nums[i];
    int n;
    cin >> n;
    Solution obj;
    cout << obj.minPatches(nums, n) << endl;
    return 0;
}