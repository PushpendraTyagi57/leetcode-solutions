#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> que;
        int level = 0;
        que.push(startGene);
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                string curr = que.front();
                que.pop();
                if (curr == endGene)
                    return level;
                for (char ch : "ACGT") {
                    for (int i = 0; i < curr.length(); i++) {
                        string neighbour = curr;
                        neighbour[i] = ch;
                        if (visited.find(neighbour) == visited.end() && bankSet.find(neighbour) != bankSet.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main () {
    string startGene, endGene;
    cin >> startGene >> endGene;
    int n;
    cin >> n;
    vector<string> bank(n);
    for (int i = 0; i < n; i++)
        cin >> bank[i];
    Solution obj;
    cout << obj.minMutation(startGene, endGene, bank);
    return 0;
}