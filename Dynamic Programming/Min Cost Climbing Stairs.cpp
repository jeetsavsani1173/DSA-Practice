// problem link --> https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=dp[1][i-1];
            dp[1][i]=min(dp[0][i-1],dp[1][i-1])+cost[i-1];
        }
        
        return min(dp[0][n],dp[1][n]);
    }
};