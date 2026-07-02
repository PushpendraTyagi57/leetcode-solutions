#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<double> left;
        multiset<double> right;
        vector<double> result;
        int i = 0, j = 0;
        while (j < n) {
            if (left.empty() || left.size() <= right.size()) {
                left.insert(double(nums[j]));
            }
            else {
                right.insert(double(nums[j]));
            }
            int leftSize = left.size();
            int rightSize = right.size();
            while (leftSize > 0 && rightSize > 0) {
                int leftMax = *left.rbegin();
                int rightMin = *right.begin();
                if (leftMax > rightMin) {
                    left.insert(rightMin);
                    right.insert(leftMax);
                    left.erase(left.find(leftMax));
                    right.erase(right.find(rightMin));
                    leftSize = left.size();
                    rightSize = right.size();

                }
                else break;
            }
            if (j - i + 1 == k) {
                if (k % 2 == 1) {
                    result.push_back(*left.rbegin());
                } 
                else {
                    result.push_back(((*left.rbegin()) + (*right.begin())) / 2.0);
                }
                if (left.find(nums[i]) != left.end())
                    left.erase(left.find(nums[i]));
                else
                    right.erase(right.find(nums[i]));
                i++;
            }
            j++;
        }
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k; cin >> k;
    Solution obj;
    vector<double> result = obj.medianSlidingWindow(nums, k);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    return 0;
}