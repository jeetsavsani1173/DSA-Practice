// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// First Solution
class Solution
{
public:
    // Greedy
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[i - 1] > 0)
                ans += (prices[i] - prices[i - 1]);
        }
        return ans;
    }
};

// Second Solution
class Solution
{
public:
    // DP
    int maxProfit(vector<int> &prices)
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
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
            //       max(Do not Sell,prevProfit - todaySellCost)
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};
