#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int currOnes = 0;
        int maxCount = 0;
        while (j < 2 * n) {
            if (nums[j % n] == 1)
                currOnes += 1;
            if (j - i + 1 > totalOnes) {
                currOnes -= nums[i % n];
                i++;
            }
            maxCount = max(maxCount, currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.minSwaps(nums) << endl;
    return 0;
}