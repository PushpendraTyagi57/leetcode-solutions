#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            string temp = to_string(nums[i]);
            for (char &ch : temp) answer.push_back(ch - '0');
        }
        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.separateDigits(nums);
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