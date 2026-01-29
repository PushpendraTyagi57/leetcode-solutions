class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int beautifulPairs = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                string firstNumber = to_string(nums[i]);
                string secondNumber = to_string(nums[j]);
                int firstDigit = firstNumber[0] - '0';
                int lastDigit = secondNumber.back() - '0';
                if (gcd(firstDigit, lastDigit) == 1) beautifulPairs++; 
            }
        }
        return beautifulPairs;
    }
};