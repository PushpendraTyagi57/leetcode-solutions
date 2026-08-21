#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSmaller(long long mid, vector<int>& coins) {
        long long correctedCount = 0;
        int n = coins.size();
        for (int expressions = 1; expressions <= (1 << n) - 1; expressions++) {
            long long LCM = 0;
            long long order = 0;
            for (int i = 0; i < n; i++) {
                if (expressions & (1 << i)) {
                    order++;
                    if (LCM == 0) {
                        LCM = coins[i];
                    }
                    else {
                        LCM = LCM * coins[i] / __gcd(LCM, (long long)coins[i]);
                    }
                }
            }
            if (order % 2 == 0) {
                correctedCount -= mid / LCM;
            }
            else {
                correctedCount += mid / LCM;
            }
        }
        return correctedCount;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long result = -1;
        long long low = 1;
        long long high = 1LL * (*max_element(coins.begin(), coins.end())) * k;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countSmaller(mid, coins) >= k) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main () {
    int n; cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int k; cin >> k;
    Solution obj;
    cout << obj.findKthSmallest(coins, k) << endl;
    return 0;
}