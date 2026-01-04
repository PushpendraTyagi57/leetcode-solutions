class Solution {
public:
    string largestEven(string s) {
        while (!s.empty()) {
            int lastDigit = s.back() - '0';
            if (lastDigit % 2 == 0)
                return s;
            s.pop_back();
        }
        return "";
    }
};
