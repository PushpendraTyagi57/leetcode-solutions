#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        vector<string> result;
        for (string &query : queries) {
            for (string &s : dictionary) {
                int diff = 0;
                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != s[i]) diff++;
                    if (diff > 2) break;
                }
                if (diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    int m;
    cin >> m;
    vector<string> queries(m);
    for (int i = 0; i < m; i++) cin >> queries[i];
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for (int i = 0; i < n; i++) cin >> dictionary[i];
    Solution obj;
    vector<string> ans = obj.twoEditWords(queries, dictionary);
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