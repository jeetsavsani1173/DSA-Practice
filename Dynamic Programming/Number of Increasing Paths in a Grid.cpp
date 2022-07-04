// problem link --> https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    long M;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>> &mat,int n,int m,vector<vector<int>> &dp)
    {
        int temp_ans=0;
        int count=0;
        for(int k=0;k<4;k++)
        {
            int newx=i+dx[k];
            int newy=j+dy[k];
            if(newx>=0 && newy>=0 && newx<n && newy<m && mat[i][j]<mat[newx][newy])
            {
                if(dp[newx][newy]!=-1)
                    temp_ans+=dp[newx][newy];
                else
                    temp_ans+=dfs(newx,newy,mat,n,m,dp);
                count++;
            }
        }
        return dp[i][j]=(temp_ans+1)%(M);
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        M=1e9+7;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                int temp=dfs(i,j,grid,n,m,dp);
                ans=(ans+temp)%M;
            }
        }
        return ans;
    }
};