#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<int, int> lower, upper;
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (islower(ch)) lower[ch] = i;
            else {
                if (upper.find(toupper(ch)) != upper.end()) continue;
                upper[toupper(ch)] = i;
            }
        }
        int count = 0;
        for (auto& element : lower) {
            char lowerElement = element.first;
            char upperElement = toupper(element.first);
            if (upper.find(upperElement) != upper.end() && lower[lowerElement] < upper[upperElement])
                count++;
        }
        return count;
    }
};

int main() {
    string word;
    cin >> word;
    Solution obj;
    cout << obj.numberOfSpecialChars(word) << endl;
    return 0;
}