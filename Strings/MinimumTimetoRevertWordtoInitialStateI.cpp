#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(string &word, int i, int n) {
        return word.substr(0, n - i) == word.substr(i, n - i);
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int i = k;
        int count = 1;
        while (i < n) {
            if (check(word, i, n)) break;
            count++;
            i += k;
        }
        return count;
    }
};

int main() {
    string word;
    int k;
    cin >> word >> k;
    Solution obj;
    cout << obj.minimumTimeToInitialState(word, k) << endl;
    return 0;
}