#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> isPrime;
    void buildIsPrime(int maxElement) {
        isPrime.resize(maxElement + 1, true);
        isPrime[0] = false, isPrime[1] = false;
        for (int num = 2; num * num <= maxElement; num++) {
            if (isPrime[num]) {
                for (int multiple = num * num; multiple <= maxElement; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxElement = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxElement = max(maxElement, nums[i]);
        }
        buildIsPrime(maxElement);
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        int steps = 0;
        unordered_set<int> seen;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int i = que.front();
                que.pop();
                if(i == n - 1) return steps;
                if (i + 1 < n && !visited[i + 1]) {
                    que.push(i + 1);
                    visited[i + 1] = true;
                }
                if (i - 1 >= 0 && !visited[i - 1]) {
                    que.push(i - 1);
                    visited[i - 1] = true;
                }
                if (!isPrime[nums[i]] || seen.count(nums[i])) continue;
                for (int multiple = nums[i]; multiple <= maxElement; multiple += nums[i]) {
                    if (mp.count(multiple) == 0) continue;
                    for (int &j : mp[multiple]) {
                        if (!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.minJumps(nums) << endl;
    return 0;
}