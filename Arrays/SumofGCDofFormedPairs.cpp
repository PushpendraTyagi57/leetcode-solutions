#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        int maxElement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxElement = max(nums[i], maxElement);
            prefixGcd[i] = gcd(nums[i], maxElement);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0, j = n - 1;
        long long sum = 0;
        while (i < j) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.gcdSum(nums) << endl;
    return 0;
}