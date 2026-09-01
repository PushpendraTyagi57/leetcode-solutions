#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int litterNumber[20][20];
        int litterCount = 0;
        int maxEnergy = energy;

        int startRow = 0;
        int startCol = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterNumber[i][j] = litterCount++;
                }
            }
        }
        if (litterCount == 0) return 0;
        int allCollectedState = (1 << litterCount) - 1;

        VVVVB visited(m, VVVB(n, VVB(energy + 1, VB(1 << litterCount, false))));
        queue<State> que;
        que.push({startRow, startCol, energy, 0});
        visited[startRow][startCol][energy][0] = true;
        int moves = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                State curr = que.front();
                que.pop();
                if (curr.collectedMask == allCollectedState) return moves;
                if (curr.energyLeft == 0) continue;
                for (auto& dir : directions) {
                    int new_i = curr.row + dir[0];
                    int new_j = curr.col + dir[1];
                    if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
                    char cell = classroom[new_i][new_j];
                    if (cell == 'X') continue;
                    int nextEnergy = curr.energyLeft - 1;
                    int nextCollectedState = curr.collectedMask;
                    if (cell == 'R') nextEnergy = maxEnergy;
                    if (cell == 'L') {
                        nextCollectedState |= (1 << litterNumber[new_i][new_j]);
                    }
                    if (!visited[new_i][new_j][nextEnergy][nextCollectedState]) {
                        visited[new_i][new_j][nextEnergy][nextCollectedState] = true;
                        que.push({new_i, new_j, nextEnergy, nextCollectedState});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

int main () {
    int n; cin >> n;
    vector<string> classroom(n);
    for (int i = 0; i < n; i++) {
        cin >> classroom[i];
    }
    int energy;
    cin >> energy;
    Solution obj;
    cout << obj.minMoves(classroom, energy) << endl;
    return 0;
}