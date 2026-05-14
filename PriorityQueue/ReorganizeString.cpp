#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, char> P;
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char& ch : s) mp[ch]++;
        priority_queue<P> pq;
        for (auto &it : mp) pq.push({it.second, it.first});
        string result = "";
        pair<int, char> prev = {-1, '#'};
        while (!pq.empty()) {
            P curr = pq.top();
            pq.pop();
            result.push_back(curr.second);
            curr.first -= 1;
            if (prev.first > 0) pq.push(prev);
            prev = curr;
        }
        if (result.size() != s.size()) return "";
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.reorganizeString(s) << endl;
    return 0;
}