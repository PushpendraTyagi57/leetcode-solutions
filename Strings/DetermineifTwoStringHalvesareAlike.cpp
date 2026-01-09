class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';  
    }
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0;
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (isVowel(s[i])) count1++;
            if (isVowel(s[i + n / 2])) count2++;
        }
        return count1 == count2;
    }
};