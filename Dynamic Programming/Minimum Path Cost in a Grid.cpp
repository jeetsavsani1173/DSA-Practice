// problem link --> https://leetcode.com/problems/minimum-path-cost-in-a-grid/

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=grid[i][j];

        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                int temp=INT_MAX;
                vector<int> cost=moveCost[grid[i][j]];
                for(int k=0;k<m;k++)
                {
                    temp=min(temp,cost[k]+dp[i+1][k]);
                }
                dp[i][j]+=temp;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
            ans=min(ans,dp[0][j]);
        
        return ans;
    }
};