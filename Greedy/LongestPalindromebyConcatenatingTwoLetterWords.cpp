#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int longestPalindrome = 0;
        for (auto &word : words) {
            string temp = word;
            reverse(temp.begin(), temp.end());
            if (mp[temp] > 0) {
                longestPalindrome += 4;
                mp[temp]--;
            }
            else {
                mp[word]++;
            }

        }
        for (auto &p : mp) {
            if (p.first[0] == p.first[1] && p.second > 0) {
                longestPalindrome += 2;
                break;
            }
        }
        return longestPalindrome;
    }
};
int main () {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    Solution obj;
    int result = obj.longestPalindrome(words);
    cout << result << endl;
}