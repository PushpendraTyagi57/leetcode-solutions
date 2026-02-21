class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            long long spell = spells[i];
            int low = 0, high = m - 1;
            int count = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (spell * potions[mid] >= success)
                    high = mid - 1;
                else low = mid + 1;
            }
            count = m - low;
            result.push_back(count);
        }
        return result;
    }
};