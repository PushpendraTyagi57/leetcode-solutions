#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> keyValuePair;
        for (auto& P : knowledge) {
            string key = P[0];
            string value = P[1];
            keyValuePair[key] = value;
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                string temp = "";
                int j = i + 1;
                while (j < n && s[j] != ')') {
                    temp += s[j];
                    j++;
                }
                if (keyValuePair.count(temp)) {
                    ans += keyValuePair[temp];
                }
                else {
                    ans += '?';
                }
                i = j;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main () {
    string s; cin >> s;
    int n; cin >> n;
    vector<vector<string>> knowledge(n, vector<string>(2));
    for (int i = 0; i < n; i++) {
        cin >> knowledge[i][0] >> knowledge[i][1];
    }
    Solution* obj = new Solution();
    cout << obj->evaluate(s, knowledge) << endl;
    return 0;
}