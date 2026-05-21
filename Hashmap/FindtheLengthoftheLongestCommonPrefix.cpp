#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();
        unordered_set<int> st;
        for (int i = 0; i < m; i++) {
            int num = arr1[i];
            while (num > 0) {
                st.insert(num);
                num /= 10;
            }
        }
        int longestPrefix = 0;
        for (int i = 0; i < n; i++) {
            int num = arr2[i];
            while (num > 0) {
                if (st.find(num) != st.end()) {
                    string temp = to_string(num);
                    longestPrefix = max(longestPrefix, (int)temp.size());
                    break;
                }
                num /= 10;
            }
        }
        return longestPrefix;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int i = 0; i < m; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];
    Solution obj;
    cout << obj.longestCommonPrefix(arr1, arr2) << endl;
    return 0;
}