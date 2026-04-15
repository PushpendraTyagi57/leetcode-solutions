#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int straightDistance = abs(i - startIndex);
                int circularDistance = n - straightDistance;
                result = min({result, straightDistance, circularDistance});
            }
        }   
        return (result == INT_MAX) ? -1 : result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    string target;
    cin >> target;
    int startIndex;
    cin >> startIndex;
    Solution obj;
    cout << obj.closestTarget(words, target, startIndex) << endl;
    return 0;
}