class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<int> toggle(101, false);
        for (int i = 0; i < n; i++) {
            toggle[bulbs[i]] = !toggle[bulbs[i]];
        }
        vector<int> result;
        for (int i = 1; i <= 100; i++) {
            if (toggle[i] == true)
                result.push_back(i);
        }
        return result;
    }
};