#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) st.push(i);
            else {
                if ((asteroids[st.top()] > 0 && asteroids[i] > 0)
                    || (asteroids[st.top()] < 0 && asteroids[i] < 0)) {
                    st.push(i);
                }
                else if (asteroids[st.top()] < 0 && asteroids[i] > 0) {
                    st.push(i);
                }
                else if (asteroids[st.top()] > 0 && asteroids[i] < 0) {
                    if (asteroids[st.top()] == abs(asteroids[i])) {
                        st.pop();
                        continue;
                    }
                    while (!st.empty() && asteroids[st.top()] > 0 && asteroids[st.top()] < abs(asteroids[i])) st.pop();
                    if (!st.empty() && asteroids[st.top()] > abs(asteroids[i])) {
                        continue;
                    }
                    if (st.empty()) st.push(i);
                    else if (asteroids[st.top()] > 0) {
                        if (asteroids[st.top()] == abs(asteroids[i])) {
                            st.pop();
                        }
                        else if (asteroids[st.top()] < abs(asteroids[i])) {
                            st.push(i);
                        }
                    }
                    else {
                        st.push(i);
                    }
                }
            }
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(asteroids[st.top()]);
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for (int i = 0; i < n; i++) cin >> asteroids[i];
    Solution obj;
    vector<int> ans = obj.asteroidCollision(asteroids);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}