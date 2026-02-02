class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] < buyPrice) buyPrice = prices[i];
            else {
                int currProfit = prices[i] - buyPrice;
                maxProfit = max(maxProfit, currProfit);
            }
        }
        return maxProfit;
    }
};