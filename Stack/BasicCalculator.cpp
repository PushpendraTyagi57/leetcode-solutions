#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        long long number = 0, result = 0;
        int sign = 1;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+') {
                result += (number * sign);
                number = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                result += (number * sign);
                number = 0;
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                number = 0, result = 0, sign = 1;
            }
            else if (s[i] == ')') {
                result += (number * sign);
                number = 0;
                int lastSign = st.top();
                st.pop();
                int lastResult = st.top();
                st.pop();
                result *= lastSign;
                result += lastResult;
            }
        }
        result += (number * sign);
        return (int)result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.calculate(s) << endl;
    return 0;
}