#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> prefixOddCount(n, 0);
        prefixOddCount[0] = (nums[0] % 2 == 1) ? 1 : 0;
        for (int i = 1; i < n; i++) {
            prefixOddCount[i] = prefixOddCount[i - 1];
            if (nums[i] % 2 == 1) prefixOddCount[i]++;
        }
        int count = 0;
        int aToB = a / b;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int currSize = j - i + 1;
                int oddCount = prefixOddCount[j] - (i - 1 >= 0 ? prefixOddCount[i - 1] : 0);
                int evenCount = currSize - oddCount;
                if (oddCount) {
                    if (1LL * evenCount * b <= 1LL * oddCount * a) count++;
                }
            }
        }
        return count;
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.countRatioSubarrays(nums, a, b) << endl;
    return 0;
}