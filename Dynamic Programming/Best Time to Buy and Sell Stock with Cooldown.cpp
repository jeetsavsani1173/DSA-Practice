// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        dp[0][1] = -1 * prices[0];

        for (int i = 2; i <= n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 2] - prices[i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i - 1]);
        }
        return max(dp[0][n], dp[1][n]);
    }
};