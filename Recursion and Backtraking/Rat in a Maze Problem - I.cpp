// problem link --> https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

class Solution{
    public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string temp="URDL";
    void rat_in_maze(int i,int j,int n,string curr,vector<vector<int>> &grid,vector<vector<bool>> &vis,vector<string>&ans)
    {
        if(i+1==n && j+1==n)
        {
            // cout<<curr<<endl;
            ans.push_back(curr);
            return;
        }
        vis[i][j]=true;
        
        for(int k=0;k<4;k++)
        {
            int newX=i+dx[k];
            int newY=j+dy[k];
            
            if(newX>=0 && newY>=0 && newX<n && newY<n && grid[newX][newY]==1 && !vis[newX][newY])
            {
                rat_in_maze(newX,newY,n,curr+temp[k],grid,vis,ans);
            }
        }
        
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        string curr="";
        rat_in_maze(0,0,n,curr,m,vis,ans);
        return ans;
    }
};
