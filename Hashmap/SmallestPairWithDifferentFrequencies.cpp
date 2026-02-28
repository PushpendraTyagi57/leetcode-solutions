#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        for (auto it1 = mp.begin(); it1 != mp.end(); ++it1) {
            for (auto it2 = next(it1); it2 != mp.end(); ++it2)
                if (it1->second != it2->second)
                    return {it1->first, it2->first};
        }
        return {-1, -1};
            
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.minDistinctFreqPair(nums);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}