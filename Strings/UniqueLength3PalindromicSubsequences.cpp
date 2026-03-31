#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstIndex(26, -1), lastIndex(26, -1);
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            if (firstIndex[s[i] - 'a'] == -1)
                firstIndex[s[i] - 'a'] = i;
            lastIndex[s[i] - 'a'] = i;
            mp[s[i]]++;
        }
        unordered_set<string> st;
        for (char firstLast = 'a'; firstLast <= 'z'; firstLast++) {
            if (mp[firstLast] < 2) continue;
            int firstAppear = firstIndex[firstLast - 'a'];
            int lastAppear = lastIndex[firstLast - 'a'];
            for (int i = firstAppear + 1; i < lastAppear; i++) {
                string temp;
                temp.push_back(s[firstAppear]);
                temp.push_back(s[i]);
                temp.push_back(s[lastAppear]);
                st.insert(temp);
            }
        }
        return st.size();
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.countPalindromicSubsequence(s) << endl;
    return 0;
}