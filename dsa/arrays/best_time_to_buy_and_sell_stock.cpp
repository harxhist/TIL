//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1969376172/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //minBuy
        //maxSell
        int maxProfit = -1;
        int buy = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            int profit = prices[i] - buy;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};