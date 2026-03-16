#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] == 1 && nums[i] % 2 == 0)
                return nums[i];
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.firstUniqueEven(nums) << endl;
    return 0;   
}