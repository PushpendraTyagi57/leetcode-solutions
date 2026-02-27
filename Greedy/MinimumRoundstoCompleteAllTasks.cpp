#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[tasks[i]]++;
        int minRounds = 0;
        for (auto i : mp) {
            int tasksToDo = i.second;
            if (tasksToDo == 1) return -1;
            else if (tasksToDo == 3 || tasksToDo == 2)
                minRounds += 1;
            else if (tasksToDo > 3) {
                if (tasksToDo % 3 == 0)
                    minRounds += tasksToDo / 3;
                else
                    minRounds += tasksToDo / 3 + 1;
            }
        }
        return minRounds;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i];
    Solution obj;
    cout << obj.minimumRounds(tasks);
    return 0;
}