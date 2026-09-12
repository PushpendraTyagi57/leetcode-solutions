#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class Node {
    public:
        long long score;
        vector<int> idxs;
        Node() {
            score = LLONG_MIN;
        }
    };

    int n;
    vector<int> nextIdx;
    vector<vector<Node>> dp;
    int findNextIdx(int target, vector<vector<int>>& intervals) {
        int result = -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] > target) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result == -1 ? n : result;
    }

    Node solve(int index, int K, vector<vector<int>>& intervals) {
        if (K == 0 || index >= n) {
            Node base;
            base.score = 0;
            return base;
        }
        if (dp[index][K].score != LLONG_MIN) return dp[index][K];

        Node skip = solve(index + 1, K, intervals);

        int originalIndex = intervals[index][3];
        int nextIndexToTake = nextIdx[index];
        long long weight = intervals[index][2];

        Node temp = solve(nextIndexToTake, K - 1, intervals);

        Node take;
        take.score = weight + temp.score;
        take.idxs = temp.idxs;
        take.idxs.push_back(originalIndex);

        sort(take.idxs.begin(), take.idxs.end());

        Node result;
        if (skip.score > take.score) {
            result = skip;
        }
        else if (skip.score < take.score) {
            result = take;
        }
        else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return dp[index][K] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++) {
            int endPoint = intervals[i][1];
            nextIdx[i] = findNextIdx(endPoint, intervals);
        }
        int K = 4;
        dp.assign(n + 1, vector<Node>(K + 1));
        return solve(0, K, intervals).idxs;
    }
};

int main () {
    int m; cin >> m;
    vector<vector<int>> intervals(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> intervals[i][0] >> intervals[0][1] >> intervals[i][2];
    }
    Solution obj;
    vector<int> ans = obj.maximumWeight(intervals);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}