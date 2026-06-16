#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseString(string res) {
        int i = 0, j = res.size() - 1;
        while (i < j) {
            swap(res[i], res[j]);
            i++, j--;
        }
        return res;
    }
    string processStr(string s) {
        string res = "";
        for (char& ch : s) {
            if (ch == '*') {
                if (!res.empty()) res.pop_back();
            }
            else if (ch == '#') res += res;
            else if (ch == '%') res = reverseString(res);
            else res.push_back(ch);
        }
        return res;
    }
};

int main() {
    string s; cin >> s;
    Solution obj;
    cout << obj.processStr(s) << endl;
    return 0;
}