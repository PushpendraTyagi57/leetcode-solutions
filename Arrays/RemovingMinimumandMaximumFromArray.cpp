#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minElement = INT_MAX, minIndex = -1;
        int maxElement = INT_MIN, maxIndex = -1;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num < minElement) {
                minElement = num;
                minIndex = i;
            }
            if (num > maxElement) {
                maxElement = num;
                maxIndex = i;
            }
        }
        if (minIndex == maxIndex) return minIndex + 1;
        return min({max(minIndex, maxIndex) + 1, (min(minIndex, maxIndex) + 1) + (n - max(minIndex, maxIndex)), n - min(minIndex, maxIndex)});
    }
};

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.minimumDeletions(nums) << endl;
    return 0;
}