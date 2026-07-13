#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int num = 1; num <= 9 ; num++) {
            int curr = num;
            int i = num + 1;
            while (curr <= high) {
                if (curr >= low) result.push_back(curr);
                if (i > 9) break;
                curr = (curr * 10) + i;
                i++;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int low, high;
    cin >> low >> high;
    Solution solution;
    vector<int> result = solution.sequentialDigits(low, high);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}