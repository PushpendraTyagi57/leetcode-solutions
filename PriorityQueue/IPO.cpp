#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<P> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }
        priority_queue<P> pq;
        sort(vec.begin(), vec.end());
        int i = 0;
        while (i < n) {
            while (i < n && w >= vec[i].first) {
                pq.push({vec[i].second, vec[i].first});
                i++;
            }
            if (k == 0 || pq.empty()) break;
            if (!pq.empty()) {
                auto curr = pq.top();
                pq.pop();
                w += curr.first;
                k--;
            }
        }
        while (k > 0 && !pq.empty()) {
            auto curr = pq.top();
            w += curr.first;
            k--;
        }
        return w;
    }
};

int main() {
    int k, w, n;
    cin >> k >> w >> n;
    vector<int> profits(n);
    for (int i = 0; i < n; i++) cin >> profits[i];
    vector<int> capital(n);
    for (int i = 0; i < n; i++) cin >> capital[i];
    Solution obj;
    cout << obj.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}