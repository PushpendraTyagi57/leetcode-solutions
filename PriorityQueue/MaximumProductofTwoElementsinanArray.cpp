#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
            while (pq.size() > 2) pq.pop();
        }
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        return (num1 - 1) * (num2 - 1);
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.maxProduct(nums) << endl;
    return 0;
}