#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long nCr(int n, int r, int k) {
        r = min(r, n - r);
        long long result = 1;
        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;
            if (result >= k) return k;
        }
        return result;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid = ' ';
        if (n % 2 == 1) mid = s[n / 2];
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2) continue;
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) count[i] = (count[i] / 2);
        string halfResult = "";
        for (int i = 0; i < n / 2; i++) {
            bool characterPlaced = false;
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    count[j] -= 1;
                    long long ways = 1;
                    int letters = 0;
                    for (int c = 0; c < 26; c++) letters += count[c];
                    for (int c = 0; c < 26; c++) {
                        if (count[c] == 0) continue;
                        ways *= nCr(letters, count[c], k);
                        letters -= count[c];
                        if (ways >= k) break;
                    }
                    if (ways >= k) {
                        halfResult.push_back(j + 'a');
                        characterPlaced = true;
                        break;
                    }
                    k -= ways;
                    count[j] += 1;
                }
            }
            if (!characterPlaced) return "";
        }
        string rev = halfResult;
        reverse(rev.begin(), rev.end());
        if (mid != ' ') halfResult.push_back(mid);
        return halfResult + rev;
    }
};

int main() {
    string s;
    cin >> s;
    int k; cin >> k;
    Solution obj;
    cout << obj.smallestPalindrome(s, k) << endl;
    return 0;
}