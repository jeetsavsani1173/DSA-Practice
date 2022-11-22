// problem link --> https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) continue;
                else if(i==n-1) dp[i][j]=grid[i][j]+dp[i][j+1];
                else if(j==m-1) dp[i][j]=grid[i][j]+dp[i+1][j];
                else dp[i][j]=grid[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
        
        return dp[0][0];
    }
};