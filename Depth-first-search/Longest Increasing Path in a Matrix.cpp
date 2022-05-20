// problem link --> https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>> &mat,int n,int m,vector<vector<int>> &dp)
    {
        int temp_ans=0;
        for(int k=0;k<4;k++)
        {
            int newx=i+dx[k];
            int newy=j+dy[k];
            if(newx>=0 && newy>=0 && newx<n && newy<m && mat[i][j]<mat[newx][newy])
            {
                if(dp[newx][newy]!=-1)
                    temp_ans=max(temp_ans,dp[newx][newy]);
                else
                    temp_ans=max(temp_ans,dfs(newx,newy,mat,n,m,dp));
            }
        }
        return dp[i][j]=temp_ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=INT_MIN;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                int temp_ans=dfs(i,j,matrix,matrix.size(),matrix[i].size(),dp);
                ans=max(ans,temp_ans);
                // cout<<temp_ans<<endl;
            }
        }
        return ans;
    }
};