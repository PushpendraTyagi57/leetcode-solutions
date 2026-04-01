#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> seatPos;
        for (int i = 0; i < n; i++)
            if (corridor[i] == 'S')
                seatPos.push_back(i);
        long long result = 1;
        if (seatPos.size() % 2 != 0 || seatPos.size() == 0) return 0;
        int prevIdx = seatPos[1];
        for (int i = 2; i < seatPos.size(); i += 2) {
            int size = seatPos[i] - prevIdx;
            result = (result * size) % MOD;
            prevIdx = seatPos[i + 1];
        }
        return result;
    }
};

int main() {
    string corridor;
    cin >> corridor;
    Solution obj;
    cout << obj.numberOfWays(corridor) << endl;
    return 0;
}