#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<int> st;
        for (char &ch : s) {
            if (ch == '*') st.pop();
            else st.push(ch);
        }
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.removeStars(s) << endl;
    return 0;
}