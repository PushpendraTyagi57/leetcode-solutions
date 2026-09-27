#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }

        string result = "";
        int flag = 1;
        for (int i = 0; i < n; i += flag) {
            if (s[i] == '(' || s[i] == ')') {
                i = mp[i];
                flag = -flag;
            }
            else {
                result += s[i];
            }
        }
        return result;
    }
};

int main () {
    string s;
    cin >> s;
    Solution* obj = new Solution();
    cout << obj->reverseParentheses(s) << endl;
    return 0;
}