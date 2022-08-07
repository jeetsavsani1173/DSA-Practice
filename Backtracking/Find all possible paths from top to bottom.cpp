// problem link --> https://practice.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1#

class Solution
{
public:
    vector<vector<int>> ans;
    void helper(int i,int j,int n,int m,vector<int> &rsf,vector<vector<int>> &grid)
    {
        if(i==n-1 && j==m-1)
        {
            rsf.push_back(grid[i][j]);
            ans.push_back(rsf);
            rsf.pop_back();
            return;
        }
        
        // down move..
        if((i+1)>=0 && (j)>=0 && (i+1)<n && (j)<m){
            rsf.push_back(grid[i][j]);
            helper(i+1,j,n,m,rsf,grid);
            rsf.pop_back();
        }
        
        //right move..
        if(i>=0 && (j+1)>=0 && i<n && (j+1)<m){
            rsf.push_back(grid[i][j]);
            helper(i,j+1,n,m,rsf,grid);
            rsf.pop_back();
        }
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> rsf;
        helper(0,0,n,m,rsf,grid);
        return ans;
    }
};