#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    Solution obj;
    bool ans = obj.uniformArray(nums1);
    cout << ((ans == 1) ? "True" : "False") << endl;
    return 0;
}