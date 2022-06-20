// problem link --> https://leetcode.com/problems/surrounded-regions/

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    void dfs(int r,int c,int n,int m,vector<vector<char>>& grid,vector<vector<bool>>& vis)
    {
        vis[r][c]=true;
        grid[r][c]='*';
        for(int i=0;i<4;i++)
        {
            int newX=r+dx[i];
            int newY=c+dy[i];
            
            if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]=='O' && !vis[newX][newY])
                dfs(newX,newY,n,m,grid,vis);
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        // first row..
        for(int j=0;j<m;j++)
            if(!vis[0][j] && grid[0][j]=='O')
                dfs(0,j,n,m,grid,vis);
        
        // last row..
        for(int j=0;j<m;j++)
            if(!vis[n-1][j] && grid[n-1][j]=='O')
                dfs(n-1,j,n,m,grid,vis);
        
        // first col..
        for(int i=0;i<n;i++)
            if(!vis[i][0] && grid[i][0]=='O')
                dfs(i,0,n,m,grid,vis);
        
        // last col..
        for(int i=0;i<n;i++)
            if(!vis[i][m-1] && grid[i][m-1]=='O')
                dfs(i,m-1,n,m,grid,vis);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O')
                    grid[i][j]='X';
                else if(grid[i][j]=='*')
                    grid[i][j]='O';
            }
    }
};