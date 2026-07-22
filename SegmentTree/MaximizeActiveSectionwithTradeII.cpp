#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> segTree;
    void buildSegTree(int left, int right, int index, vector<int>& pairSum) {
        if (left == right) {
            segTree[index] = pairSum[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegTree(left, mid, 2 * index + 1, pairSum);
        buildSegTree(mid + 1, right, 2 * index + 2, pairSum);
        segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

    int RMQ(int left, int right, int index, int start, int end) {
        if (start > end) return INT_MIN;
        if (right < start || left > end) return INT_MIN;
        if (start <= left && right <= end) return segTree[index];
        int mid = left + (right - left) / 2;
        return max(RMQ(left, mid, 2 * index + 1, start, end), RMQ(mid + 1, right, 2 * index + 2, start, end)); 
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int activeCount = count(s.begin(), s.end(), '1');
        vector<int> blockStart;
        vector<int> blockEnd;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                blockStart.push_back(start);
                blockEnd.push_back(i - 1);
            }
            else i++;
        }
        int m = blockStart.size();
        if (m <= 1) {
            return vector<int>(queries.size(), activeCount);
        }

        vector<int> blockSize(m);
        for (int i = 0; i < m; i++) {
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }
        int N = m - 1;
        vector<int> pairSum(N);
        for (int i = 0; i < N; i++) {
            pairSum[i] = blockSize[i] + blockSize[i + 1];
        }
        segTree.resize(4 * N);
        buildSegTree(0, N - 1, 0, pairSum);
        vector<int> result;
        for (auto& query : queries) {
            int L = query[0];
            int R = query[1];
            int low = lower_bound(blockEnd.begin(), blockEnd.end(), L) - blockEnd.begin();
            int high = upper_bound(blockStart.begin(), blockStart.end(), R) - blockStart.begin() - 1;
            int maxPairSum = 0;
            if (low < high) {
                int firstLen = blockEnd[low] - max(blockStart[low], L) + 1;
                int lastLen = min(blockEnd[high], R) - blockStart[high] + 1;
                if (high - low == 1) {
                    maxPairSum = firstLen + lastLen;
                }
                else {
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = lastLen + blockSize[high - 1];
                    int RMQMaxPairSum = RMQ(0, N - 1, 0, low + 1, high - 2);
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }
            result.push_back(maxPairSum + activeCount);
        }
        return result;
    }
};

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<vector<int>> queries(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<int> ans = obj.maxActiveSectionsAfterTrade(s, queries);
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