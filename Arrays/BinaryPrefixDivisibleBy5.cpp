#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> answer(n);
        int remainder = 0;
        for (int i = 0; i < n; i++) {
            remainder = (remainder * 2 + nums[i]) % 5;
            answer[i] = (remainder == 0);
        }
        return answer;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<bool> result = solution.prefixesDivBy5(nums);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << (result[i] ? "true" : "false");
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}