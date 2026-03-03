#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int start, int end, string &word, int k) {
        int result = 0;
        for (int unique_char = 1; unique_char <= 26 && unique_char * k <= end - start + 1; unique_char++) {
            vector<int> count(26, 0);
            int good = 0;
            int i = start;
            int windowLength = unique_char * k;
            for (int j = start; j <= end; j++) {
                char ch = word[j];
                count[ch - 'a']++;
                if (count[ch - 'a'] == k)
                    good += 1;
                else if (count[ch - 'a'] == k + 1)
                    good -= 1;
                if (j - i + 1 > windowLength) {
                    if (count[word[i] - 'a'] == k)
                        good -= 1;
                    else if (count[word[i] - 'a'] == k + 1)
                        good += 1;
                    count[word[i] - 'a']--;
                    i++;
                }
                if (good == unique_char)
                    result += 1;
            }
        }
        return result;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int last = 0;
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (abs(word[i] - word[i - 1]) > 2) {
                result += solve(last, i - 1, word, k);
                last = i;
            }
        }
        result += solve(last, n - 1, word, k);
        return result;
    }
};

int main() {
    string word;
    cin >> word;
    int k;
    cin >> k;
    Solution obj;
    cout << obj.countCompleteSubstrings(word, k) << endl;
    return 0;
}