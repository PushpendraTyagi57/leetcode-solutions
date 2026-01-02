class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        long reversedInteger = 0;
        int temp = x;
        while (temp > 0) {
            int rem = temp % 10;
            reversedInteger = reversedInteger * 10 + rem;
            temp = temp / 10;
        }
        if (reversedInteger == x) return true;
        return false;
    }
};