#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    string solve(string& str, unordered_set<string>& st, vector<string>& nums) {
        if (str.size() == n) {
            if (st.find(str) == st.end()) return str;
            return "";
        }
        str.push_back('1');
        string res1 = solve(str, st, nums);
        if (res1.size() == n && st.find(res1) == st.end()) return res1;
        str.pop_back();
        str.push_back('0');
        string res2  = solve(str, st, nums);
        if (res2.size() == n && st.find(res2) == st.end()) return res2;
        str.pop_back();
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st;
        n = nums.size();
        for (int i = 0; i < n; i++)
            st.insert(nums[i]);
        string str;
        return solve(str, st, nums);
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution obj;
    cout << obj.findDifferentBinaryString(nums) << endl;
    return 0;
}