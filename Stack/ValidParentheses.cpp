#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else {
                if (st.empty()) return false;
                if (st.top() == '(' && ch == ')') st.pop();
                else if (st.top() == '[' && ch == ']') st.pop();
                else if (st.top() == '{' && ch == '}') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    bool ans = obj.isValid(s);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}