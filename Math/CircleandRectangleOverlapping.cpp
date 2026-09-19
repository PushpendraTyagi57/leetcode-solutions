#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi, yi;
        if (x1 > xCenter) xi = x1;
        else if (x2 < xCenter) xi = x2;
        else xi = xCenter;

        if (y1 > yCenter) yi = y1;
        else if (y2 < yCenter) yi = y2;
        else yi = yCenter;

        int dist = sqrt((xi - xCenter)*(xi - xCenter) + (yi - yCenter)*(yi-yCenter));
        return dist <= radius;
    }
};

int main () {
    int radius, xCenter, yCenter, x1, y1, x2, y2;
    cin >> radius, xCenter, yCenter, x1, y1, x2, y2;
    Solution obj;
    cout << (obj.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2) ? "true" : "false") << endl;
    return 0;
}