// problem link --> https://leetcode.com/problems/unique-paths-iii/

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

class Solution {
public:
    int count;
    bool isvalid(vector<vector<int>> &grid,vector<vector<bool>> &vis)
    {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==false)
                {
                    if(grid[i][j]!=-1)
                        return false;
                }
            }
        }
        return true;
    }
    void helper(int r,int c,int n,int m,vector<vector<int>> &grid,vector<vector<bool>> &vis)
    {
        if(grid[r][c]==2)
        {
            if(isvalid(grid,vis))
                count++;
        }
        for(int i=0;i<4;i++)
        {
            int newX=r+dx[i];
            int newY=c+dy[i];
            
            if(newX>=0 && newX<n && newY>=0 && newY<m && vis[newX][newY]==false && grid[newX][newY]!=-1)
            {
                vis[newX][newY]=true;
                helper(newX,newY,n,m,grid,vis);
                vis[newX][newY]=false;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        count=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                {
                    vis[i][j]=true;
                    helper(i,j,grid.size(),grid[0].size(),grid,vis);
                    break;
                }
        
        return count;
    }
};