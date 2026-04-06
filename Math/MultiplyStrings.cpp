#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> nums(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int curr = nums[i + j + 1] + prod;
                nums[i + j + 1] = curr % 10;
                nums[i + j] += curr / 10; 
            }
        }
        int k = 0;
        while (k < m + n && nums[k] == 0) k++;
        if (k == m + n) return "0";
        string result = "";
        for (int i = k; i < m + n; i++)
            result += (nums[i] + '0');
        return result;
    }
};

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    Solution obj;
    cout << obj.multiply(num1, num2) << endl;
    return  0;
}