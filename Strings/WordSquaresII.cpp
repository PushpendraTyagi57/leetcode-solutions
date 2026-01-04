class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < n; l++) {
                        if (l == i || l == j || l == k) continue;

                        string &top = words[i];
                        string &left = words[j];
                        string &right = words[k];
                        string &bottom = words[l];

                        if (top[0] != left[0]) continue;
                        if (top[3] != right[0]) continue;
                        if (bottom[0] != left[3]) continue;
                        if (bottom[3] != right[3]) continue;

                        ans.push_back({top, left, right, bottom});
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};