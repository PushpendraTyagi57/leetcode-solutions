#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0, longest = 0;
        for (char &ch : s) {
            if (ch == '(') left++;
            else right++;
            if (left == right) longest = max(longest, left * 2);
            else if (right > left) {
                left = 0, right = 0;
            }
        }
        left = 0, right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) longest = max(longest, left * 2);
            else if (left > right) {
                left = 0, right = 0;
            }
        }
        return longest;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.longestValidParentheses(s) << endl;
    return 0;
}