#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        unordered_set<int> st;
        for (int i = 0; i < m; i++)
            st.insert(banned[i]);
        int count = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                if (sum + i > maxSum) break;
                sum += i;
                count++;
            }
        }
        return count;
    }
};

int main() {
    int m;
    cin >> m;
    vector<int> banned(m);
    for (int i = 0; i < m; i++)
        cin >> banned[i];
    int n;
    cin >> n;
    int maxSum;
    cin >> maxSum;
    Solution obj;
    cout << obj.maxCount(banned, n, maxSum) << endl;
    return 0;
}