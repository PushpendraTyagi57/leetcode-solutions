class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int result = 0;
        vector<int> count(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (citations[i] < n) count[citations[i]]++;
            else count[n]++;
        }
        for (int i = n; i >= 0; i--) {
            result += count[i];
            if (result >= i) return i;
        }
        return 0;
    }
};