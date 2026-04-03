#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for (char &ch : s)
            count[ch - 'a']++;
        string result = "";
        for (char &ch : order) {
            while (count[ch - 'a']--) result.push_back(ch);
        }
        for (char &ch : s) {
            if (count[ch - 'a'] > 0) result.push_back(ch);
        }
        return result;
    }
};

int main() {
    string order, s;
    cin >> order >> s;
    Solution obj;
    cout << obj.customSortString(order, s) << endl;
    return 0;
}