#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            mp[ch]++;
        }
        vector<pair<int, char>> count;
        for (auto& it : mp) {
            count.push_back({it.second, it.first});
        }
        sort(count.rbegin(), count.rend());
        int cost = 0;
        for (int i = 0; i < count.size(); i++) {
            if (i < 8) cost += count[i].first * 1;
            else if (i < 16) cost += count[i].first * 2;
            else if (i < 24) cost += count[i].first * 3;
            else cost += count[i].first * 4;
        }
        return cost;
    }
};

int main() {
    string word; cin >> word;
    Solution obj;
    cout << obj.minimumPushes(word) << endl;
    return 0;
}