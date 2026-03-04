#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0, j = 0;
        int windowSum = 0;
        int countZero = 0;
        int result = 0;
        while (j < n) {
            windowSum += nums[j];
            while (i < j && (nums[i] == 0 || windowSum > goal)) {
                if (nums[i] == 0)
                    countZero++;
                else
                    countZero = 0;
                windowSum -= nums[i];
                i++;
            }
            if (windowSum == goal)
                result += 1 + countZero;
            j++;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int goal;
    cin >> goal;
    Solution obj;
    cout << obj.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}