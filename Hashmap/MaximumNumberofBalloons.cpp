#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, int> required {
        {'b', 1},
        {'a', 1},
        {'l', 2},
        {'o', 2},
        {'n', 1} 
    };
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> freq(26, 0);
        for (char& ch : text)
            freq[ch - 'a']++;
        int maxBalloons = INT_MAX;
        for (auto& it : required) {
            char ch = it.first;
            int requiredFreq = it.second;
            int currFreq = freq[ch - 'a'];
            if (currFreq == 0) return 0;
            maxBalloons = min(maxBalloons, currFreq / requiredFreq);
        }
        return maxBalloons;
    }
};

int main() {
    string text; cin >> text;
    Solution obj;
    cout << obj.maxNumberOfBalloons(text) << endl;
    return 0;
}