#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string result = "";
        while (!pq.empty()) {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            if (result.size() >= 2 && result[result.size() - 1] == currChar && result[result.size() - 2] == currChar) {
                if (pq.empty()) break;
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                result.push_back(nextChar);
                nextCount--;
                if (nextCount > 0) pq.push({nextCount, nextChar});
            }
            else {
                currCount--;
                result.push_back(currChar);
            }
            if (currCount > 0) pq.push({currCount, currChar});
        }
        return result;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Solution obj;
    cout << obj.longestDiverseString(a, b, c) << endl;
    return 0;
}