// problem link --> https://leetcode.com/problems/number-of-enclaves/

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    void dfs(int r,int c,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        vis[r][c]=true;
        grid[r][c]=2;
        for(int i=0;i<4;i++)
        {
            int newX=r+dx[i];
            int newY=c+dy[i];
            
            if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1 && !vis[newX][newY])
                dfs(newX,newY,n,m,grid,vis);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        // first row..
        for(int j=0;j<m;j++)
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0,j,n,m,grid,vis);
        
        // last row..
        for(int j=0;j<m;j++)
            if(!vis[n-1][j] && grid[n-1][j]==1)
                dfs(n-1,j,n,m,grid,vis);
        
        // first col..
        for(int i=0;i<n;i++)
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,n,m,grid,vis);
        
        // last col..
        for(int i=0;i<n;i++)
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,n,m,grid,vis);
        
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    cnt++;
            }
        return cnt;
    }
};