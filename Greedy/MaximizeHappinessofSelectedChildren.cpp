#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        long long maxSum = 0;
        int time = 0;
        sort(happiness.begin(), happiness.end());
        int i = n - 1;
        while (i >= 0 && k--) {
            int val = happiness[i] - time;
            if (val <= 0) break;
            maxSum += val;
            time++;
            i--;
        }
        return maxSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> happiness(n);
    for (int i = 0; i < n; i++)
        cin >> happiness[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maximumHappinessSum(happiness, k) << endl;
    return 0;
}