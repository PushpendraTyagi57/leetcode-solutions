#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char &ch : tasks)
            freq[ch - 'A']++;
        sort(freq.begin(), freq.end());
        int maxFreq = freq[25];
        int holes = maxFreq - 1;
        int idleSlots = holes * n;
        for (int i = 24; i >= 0; i--)
            idleSlots -= min(freq[i], holes);
        if (idleSlots > 0)
            return tasks.size() + idleSlots;
        return tasks.size();
    }
};

int main() {
    int m;
    cin >> m;
    vector<char> tasks(m);
    for (int i = 0; i < m; i++)
        cin >> tasks[i];
    int n;
    cin >> n;
    Solution obj;
    cout << obj.leastInterval(tasks, n) << endl;
    return 0;
}