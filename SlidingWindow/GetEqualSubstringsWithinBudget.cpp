#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) { 
        int n = s.size();
        int i = 0, j = 0;
        int maxLength = 0;
        int currCost = 0;
        while (j < n) {
            currCost += abs(s[j] - t[j]);
            while (currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};

int main() {
    string s;
    string t;
    cin >> s >> t;
    int maxCost;
    cin >> maxCost;
    Solution obj;
    cout << obj.equalSubstring(s, t, maxCost) << endl;
    return 0;
}