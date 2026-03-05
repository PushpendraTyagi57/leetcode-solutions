#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i = 0;
        for (; i < n - 1; i++) {
            if (heights[i + 1] - heights[i] <= 0) continue;
            int diff = heights[i + 1] - heights[i];
            if (bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders > 0) {
                if (!pq.empty()) {
                    int maxBricksPast = pq.top();
                    if (maxBricksPast > diff) {
                        pq.pop();
                        bricks += maxBricksPast;
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else break;
        }
        return i;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    int bricks, ladders;
    cin >> bricks >> ladders;
    Solution obj;
    cout << obj.furthestBuilding(heights, bricks, ladders) << endl;
    return 0;
}