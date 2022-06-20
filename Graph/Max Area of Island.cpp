// problem link --> https://leetcode.com/problems/max-area-of-island/

 int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    void dfs(int r,int c,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis,int &count)
    {
        vis[r][c]=true;
        count++;
        for(int i=0;i<4;i++)
        {
            int newX=r+dx[i];
            int newY=c+dy[i];
            
            if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1 && !vis[newX][newY])
                dfs(newX,newY,n,m,grid,vis,count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int count=0;
                    dfs(i,j,n,m,grid,vis,count);
                    ans=max(ans,count);
                }
            }
        
        return ans;
    }
};