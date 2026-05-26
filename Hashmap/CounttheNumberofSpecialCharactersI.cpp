#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> lower, upper;
        for (char& ch : word) {
            if (islower(ch)) lower.insert(ch);
            else upper.insert(ch);
        }
        int count = 0;
        for (auto& element : lower) {
            if (upper.find(toupper(element)) != upper.end()) count++;
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