#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int m = pushed.size();
        int i = 0, j = 0;
        while (i < m && j < m) {
            st.push(pushed[i]);
            while (!st.empty() && j < m && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> pushed(n), popped(n);
    for (int i = 0; i < n; i++) cin >> pushed[i];
    for (int i = 0; i < n; i++) cin >> popped[i];
    Solution obj;
    bool ans = obj.validateStackSequences(pushed, popped);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}