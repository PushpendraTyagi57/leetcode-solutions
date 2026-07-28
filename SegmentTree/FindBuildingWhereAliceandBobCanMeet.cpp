#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> segTree;
    void buildSegmentTree(int left, int right, int index, vector<int>& heights) {
        if (left == right) {
            segTree[index] = left;
            return;
        }

        int mid = left + (right - left) / 2;
        buildSegmentTree(left, mid, 2 * index + 1, heights);
        buildSegmentTree(mid + 1, right, 2 * index + 2, heights);

        int leftIndex = segTree[2 * index + 1];
        int rightIndex = segTree[2 * index + 2];

        if (heights[leftIndex] >= heights[rightIndex]) segTree[index] = leftIndex;
        else segTree[index] = rightIndex;
    }
    int RMIQ (int left, int right, int index, int start, int end, vector<int>& heights) {
        if (end < left || start > right) return -1;
        if (start <= left && end >= right) return segTree[index];

        int mid = left + (right - left) / 2;

        int leftIndex = RMIQ(left, mid, 2 * index + 1, start, end, heights);
        int rightIndex = RMIQ(mid + 1, right, 2 * index + 2, start, end, heights);

        if (leftIndex == -1) return rightIndex;
        if (rightIndex == -1) return leftIndex;

        if (heights[leftIndex] >= heights[rightIndex]) return leftIndex;
        return rightIndex;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree.resize(4 * n);
        buildSegmentTree(0, n - 1, 0, heights);
        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b) {
                answer[i] = a;
                continue;
            }
            if (heights[a] < heights[b]) {
                answer[i] = b;
                continue;
            }

            int L = b + 1;
            int R = n - 1;
            int idx = -1;
            while (L <= R) {
                int mid = L + (R - L) / 2;
                int getIdx = RMIQ(0, n - 1, 0, L, mid, heights);
                if (getIdx != -1 && heights[getIdx] > heights[a] && heights[getIdx] > heights[b]) {
                    idx = getIdx;
                    R = mid - 1;
                }
                else {
                    L = mid + 1;
                }
            }
            answer[i] = idx;
        }
        return answer;
    }
};

int main() {
    int n; cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];
    int q; cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<int> ans = obj.leftmostBuildingQueries(heights, queries);
    cout << "[";
    for (int i = 0; i < q; i++) {
        cout << ans[i];
        if (i != q - 1) cout << ",";
    }
    cout << "]";
    return 0;
}