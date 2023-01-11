// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution
{
public:
    // Make each day as potential selling-day or potential-buying day
    int maxProfit(vector<int> &prices)
    {
        // here we are making each day as a selling-day..
        int mn = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};