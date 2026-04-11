#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n), rightSmall(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) leftSmall[i] = 0;
            else leftSmall[i] = st.top() + 1;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) rightSmall[i] = n - 1;
            else rightSmall[i] = st.top() - 1;
            st.push(i);
        }
        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];
    Solution obj;
    cout << obj.largestRectangleArea(heights) << endl;
    return 0;
}