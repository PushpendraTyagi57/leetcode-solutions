#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) return 0;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < -8)) return 0;
            num = num * 10 + digit;
        }
        return num;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int reversedNum = reverse(nums[i]);
            arr.push_back(reversedNum);
        }
        unordered_set<int> st;
        for (int &num : arr) st.insert(num);
        return st.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.countDistinctIntegers(nums) << endl;
    return 0;
}