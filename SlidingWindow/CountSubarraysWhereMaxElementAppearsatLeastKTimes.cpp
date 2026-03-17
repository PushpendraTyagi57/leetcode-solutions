#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        int i = 0, j = 0;
        long long count = 0;
        int maxFreq = 0;
        while (j < n) {
            if (nums[j] == maxElement) maxFreq++;
            while (maxFreq >= k) {
                count += (n - j);
                if (nums[i] == maxElement) maxFreq--;
                i++;
            }
            j++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.countSubarrays(nums, k) << endl;
    return 0;
}