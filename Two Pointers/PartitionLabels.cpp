#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        vector<int> result;
        int i = 0;
        int maxPartition = INT_MIN;
        int toFindNextPartition = 0;
        while (i < s.size()) {
            maxPartition = max(maxPartition, mp[s[i]]);
            if (i == maxPartition) {
                result.push_back(i - toFindNextPartition + 1);
                toFindNextPartition = i + 1;
            }
            i++;
        }
        return result;
    }
};

int main () {
    string s;
    cin >> s;
    Solution obj;
    vector<int> ans = obj.partitionLabels(s);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}