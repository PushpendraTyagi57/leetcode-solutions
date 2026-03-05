#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;
        vector<int> freq;
        for (auto &it : mp)
            freq.push_back(it.second);
        int unique = freq.size();
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] <= k) {
                k -= freq[i];
                unique--;
            }
            else break;
        }
        return unique;
    }   
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.findLeastNumOfUniqueInts(arr, k) << endl;
    return 0;
}