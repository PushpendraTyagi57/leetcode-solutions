#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> getPSE(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) result[i] = -1;
            else {
                while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
                result[i] = (st.empty()) ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> getNSE(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) result[i] = n;
            else {
                while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
                result[i] = (st.empty()) ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> PSE = getPSE(arr, n);
        vector<int> NSE = getNSE(arr, n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long leftElements = i - PSE[i];
            long long rightElements = NSE[i] - i;
            long long totalSubarrays = leftElements * rightElements;
            long long currSum = totalSubarrays * arr[i];
            sum = (sum + currSum) % MOD;
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.sumSubarrayMins(arr) << endl;
    return 0;
}