#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        vector<int> result;
        for (int &num : changed)
            mp[num]++;
        for (int &num : changed) {
            int twice = num * 2;
            if (mp[num] == 0) continue;
            if (mp.find(twice) == mp.end() || mp[twice] == 0)
                return {};
            result.push_back(num);
            mp[twice]--;
            mp[num]--;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> changed(n);
    for (int i = 0; i < n; i++)
        cin >> changed[i];
    Solution obj;
    vector<int> ans = obj.findOriginalArray(changed);
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