#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int minElement = *min_element(nums.begin(), nums.end());
        
        return sum - n * minElement;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution* obj = new Solution();
    cout << obj->minMoves(nums) << endl;
    return 0;
}