class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxQf = -1;
        int m = towers.size();
        int xCoordinate = -1;
        int yCoordinate = -1;
        for (int i = 0; i < m; i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];
            
            int dist = abs(x - center[0]) + abs(y - center[1]);
            if (dist > radius) continue;

            if (q > maxQf) {
                xCoordinate = x;
                yCoordinate = y;
                maxQf = q;
            }
            else if (q == maxQf) {
                if (x < xCoordinate) {
                    xCoordinate = x;
                    yCoordinate = y;
                }
                else if (x == xCoordinate && y < yCoordinate) yCoordinate = y;
            }
                
        }
        return {xCoordinate, yCoordinate};
    }
};