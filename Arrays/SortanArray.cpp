#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(int low, int high, vector<int>& nums) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(low, mid, nums);
        mergeSort(mid + 1, high, nums);

        merge(low, mid, high, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n - 1, nums);
        return nums;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    vector<int> sortedArray = obj.sortArray(nums);
    cout << "[";
    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i];
        if (i != sortedArray.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
    return 0;
}