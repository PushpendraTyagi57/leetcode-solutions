#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] >= rec2[2] || rec2[0] >= rec1[2] || rec1[1] >= rec2[3] || rec2[1] >= rec1[3])
            return false;
        return true;
    }
};

int main () {
    vector<int> rec1(4), rec2(4);
    for (int i = 0; i < 4; i++) {
        cin >> rec1[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> rec2[i];
    }
    Solution obj;
    cout << ((obj.isRectangleOverlap(rec1, rec2) ? "true" : "false")) << endl;
    return 0;
}