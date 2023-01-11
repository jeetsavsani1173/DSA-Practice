// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 0 - prices[0];
        for (int i = 1; i < n; i++)
        {
            // Assume today as a potential buying day..
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            //       max(Do not buy,prevProfit - todayBuyCost)

            // Assume today as a potential Selling day..
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i] - fee);
            //       max(Do not Sell,prevProfit - todaySellCost-fees for one complete Transaction)
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};