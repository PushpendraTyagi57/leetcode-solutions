#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int num) {
        if (num == 0) return 0;
        string result = "";
        while (num > 0) {
            result.push_back((num % 10) + '0');
            num /= 10;
        }
        return stoi(result);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int minDistance = INT_MAX;
        for (int i = 0; i < n; i++) {
            int temp = reverse(nums[i]);
            if (mp.find(temp) != mp.end()) {
                vector<int>& vec = mp[temp];
                for (int idx : vec) {
                    if (idx > i)
                        minDistance = min(minDistance, abs(i - idx));
                }
                if (minDistance == 1) return minDistance;
            }
        }
        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.minMirrorPairDistance(nums) << endl;
    return 0;
}