#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    bool possible(int idx, vector<string>& arr, unordered_set<char>& usedCharacters) {
        unordered_set<char> temp;
        for (char& ch : arr[idx]) {
            if (temp.count(ch)) return false;
            if (usedCharacters.count(ch)) return false;
            temp.insert(ch);
        }
        return true;
    }
    int solve(int idx, vector<string>& arr, unordered_set<char> usedCharacters) {
        if (idx >= n) return 0;
        int take = 0;
        if (possible(idx, arr, usedCharacters)) {
            auto newUsedCharacters = usedCharacters;
            for (char& ch : arr[idx])
                newUsedCharacters.insert(ch);
            take = arr[idx].size() + solve(idx + 1, arr, newUsedCharacters);
        }
        int skip = solve(idx + 1, arr, usedCharacters);
        return max(take, skip);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        unordered_set<char> usedCharacters;
        return solve(0, arr, usedCharacters);
    }
};

int main() {
    int m;
    cin >> m;
    vector<string> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i];
    Solution obj;
    cout << obj.maxLength(arr) << endl;
    return 0;
}