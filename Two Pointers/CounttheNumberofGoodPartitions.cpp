#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> lastAppearance;
        for (int i = 0; i < n; i++)
            lastAppearance[nums[i]] = i;
        int result = 1;
        int i = 0, j = 0;
        j = max(j, lastAppearance[nums[0]]);
        while (i < n) {
            if (i > j)
                result = (result * 2) % M;
            j = max(j, lastAppearance[nums[i]]);
            i++;
        }
        return result;
        
    }
};
int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.numberOfGoodPartitions(nums) << endl;
}