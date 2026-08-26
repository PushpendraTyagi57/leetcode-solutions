#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count1 = 0;
        int i = 0, j = 0;
        string ans = "";
        while (j < n) {
            if (s[j] == '1') count1++;
            while (i <= j && count1 > k) {
                if (s[i] == '1') count1--;
                i++;
            }
            while (i <= j && count1 == k && s[i] == '0') i++;
            if (count1 == k) {
                string temp = s.substr(i, j - i + 1);
                if (ans == "" ||
                    temp.size() < ans.size() ||
                    (temp.size() == ans.size() && temp < ans)) {
                        ans = temp;
                    }
            }
            j++;
        }
        return ans;
    }
};

int main () {
    string s;
    int k;
    cin >> s >> k;
    Solution obj;
    cout << obj.shortestBeautifulSubstring(s, k) << endl;
    return 0;
}