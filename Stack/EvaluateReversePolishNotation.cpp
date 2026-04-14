#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int secondNum = st.top();
                st.pop();
                int firstNum = st.top();
                st.pop();
                int value = firstNum + secondNum;
                st.push(value);
            }
            else if (tokens[i] == "-") {
                int secondNum = st.top();
                st.pop();
                int firstNum = st.top();
                st.pop();
                int value = firstNum - secondNum;
                st.push(value);
            }
            else if (tokens[i] == "*") {
                int secondNum = st.top();
                st.pop();
                int firstNum = st.top();
                st.pop();
                int value = firstNum * secondNum;
                st.push(value);
            }
            else if (tokens[i] == "/") {
                int secondNum = st.top();
                st.pop();
                int firstNum = st.top();
                st.pop();
                int value = firstNum / secondNum;
                st.push(value);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++) cin >> tokens[i];
    Solution obj;
    cout << obj.evalRPN(tokens) << endl;
    return 0;
}