#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int pickCount = n / 3;
        int i = n - 2;
        int sum = 0;
        while (pickCount--) {
            sum += piles[i];
            i -= 2;
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    Solution obj;
    cout << obj.maxCoins(piles) << endl;
    return 0;
}