#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isVowel(char& ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m = words.size(), n = queries.size();
        vector<int> prefix(m);
        vector<int> answer(n);
        int sum = 0;
        for (int i = 0; i < m; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) sum++;
            prefix[i] = sum;
        }
        for (int i = 0; i < n; i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            answer[i] = prefix[R] - ((L > 0) ? prefix[L - 1] : 0);
        }
        return answer;
    }
};

int main() {
    int m; cin >> m;
    vector<string> words(m);
    for (int i = 0; i < m; i++) cin >> words[i];
    int n; cin >> n;
    vector<vector<int>> queries(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> queries[i][0] >> queries[i][1];
    Solution solution;
    vector<int> answer = solution.vowelStrings(words, queries);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i < n - 1) cout << ",";
    }
    cout << "]";
    return 0;
}