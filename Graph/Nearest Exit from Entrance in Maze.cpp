// problem link --> https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({entrance[0],entrance[1],0});
        vis[entrance[0]][entrance[1]]=true;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int x=it[0],y=it[1];
            int dis=it[2];
            
            for(int k=0;k<4;k++)
            {
                int newX=x+dx[k];
                int newY=y+dy[k];
                
                if(newX>=0 && newY>=0 && newX<n && newY<m && maze[newX][newY]=='.' && vis[newX][newY]==false)
                {
                    vis[newX][newY]=true;
                    q.push({newX,newY,dis+1});
                    
                    if(newX==0 || newY==0 || newX==(n-1) || newY==(m-1))
                        return dis+1;
                }
            }
        }
        return -1;
    }
};