#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<char, int> P;
    struct lambda {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<P, vector<P>, lambda> pq;
        unordered_map<char, int> mp;
        for (char &ch : s)
            mp[ch]++;
        for (auto &it : mp)
            pq.push({it.first, it.second});
        string result = "";
        while (!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            result += string(temp.second, temp.first);
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.frequencySort(s) << endl;
    return 0;
}