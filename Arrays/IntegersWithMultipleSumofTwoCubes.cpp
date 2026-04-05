#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> freq;
        for (int i = 0; ; i++) {
                    
            int num1 = i * i * i;
            if (num1 > n) break;
            for (int j = i + 1; j <= n; j++) {
                int num2 = j * j * j;
                if (num1 + num2 > n) break;
                freq[num1 + num2]++;
            }
        }
        vector<int> result;
        for (auto &it : freq) {
            if (it.second >= 2) result.push_back(it.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    Solution obj;
    vector<int> ans = obj.findGoodIntegers(n);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}