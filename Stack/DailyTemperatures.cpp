#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) ans[i] = 0;
            else {
                while (!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
                ans[i] = (st.empty()) ? 0 : st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) cin >> temperatures[i];
    Solution obj;
    vector<int> ans = obj.dailyTemperatures(temperatures);
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}