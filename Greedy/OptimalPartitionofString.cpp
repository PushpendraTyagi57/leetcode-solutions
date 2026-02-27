#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int partitions = 1;
        int i = 0;
        while (i < n) {
            unordered_map<char, int> mp;
            int j = i;
            while (j < n) {
                mp[s[j]]++;
                if (mp[s[j]] > 1) {
                    partitions++;
                    break;
                }
                j++;
            }
            i = j;
        }
        return partitions;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.partitionString(s);
    return 0;
}