#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();
        unordered_map<char, int> charMp;
        unordered_map<int, int> digitMp;
        int totalDistance = 0;
        unordered_set<string> charSt;
        unordered_set<string> digitSt;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) digitMp[s[i] - '0']++;
            else charMp[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (!isdigit(s[i])) {
                char c = s[i];
                int startDist = c - 'a';
                char m = 'z' - startDist;
                string key = string(1, min(c, m)) + string(1, max(c, m));
                if (charSt.count(key)) continue;
                int freqC = charMp[c];
                int freqM = 0;
                if (charMp.find(m) != charMp.end()) freqM = charMp[m];
                totalDistance += abs(freqC - freqM);
                charSt.insert(key);
            }
            else {
                int c = s[i] - '0';
                int m = 9 - c;
                string key = to_string(min(c, m)) + "#" + to_string(max(c, m));
                if (digitSt.count(key)) continue;
                int freqC = digitMp[c];
                int freqM = 0;
                if (digitMp.find(m) != digitMp.end()) freqM = digitMp[m];
                totalDistance += abs(freqC - freqM);
                digitSt.insert(key);
            }
        }
        return totalDistance;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.mirrorFrequency(s) << endl;
    return 0;
}