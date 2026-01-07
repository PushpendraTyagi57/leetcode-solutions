class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };
        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };
        string result = "";
        for (int i = 0; i < 13; i++) {
            if (num == 0) break;
            int times = num / values[i];
            while (times != 0) {
                result += symbols[i];
                times--;
            }
            num %= values[i];
        }
        return result;
    }
};