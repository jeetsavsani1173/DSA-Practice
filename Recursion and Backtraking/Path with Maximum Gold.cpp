// problem link --> https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    
    int dfs(int r,int c,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>&vis)
    {
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c] || grid[r][c]==0)
            return 0;
        vis[r][c]=true;
        int temp_ans=0;
        for(int i=0;i<4;i++)
        {
            temp_ans=max(temp_ans,dfs(r+dx[i],c+dy[i],n,m,grid,vis));
        }
        vis[r][c]=false;
        return temp_ans+grid[r][c];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxGold=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                maxGold=max(maxGold,dfs(i,j,n,m,grid,vis));
        return maxGold;
    }
};