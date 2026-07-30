#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for (char& ch : word) freq[ch - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int cost = 0;
        int k = 1;
        for (int i = 0; i < 26; i++) {
            if (i < 8) cost += freq[i] * 1;
            else if (i < 16) cost += freq[i] * 2;
            else if (i < 24) cost += freq[i] * 3;
            else cost += freq[i] * 4;
        }
        return cost;
    }
};

int main () {
    string word; cin >> word;
    Solution obj;
    cout << obj.minimumPushes(word) << endl;
    return 0;
}