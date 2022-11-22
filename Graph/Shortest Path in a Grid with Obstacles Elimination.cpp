// problem link --> https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int k)
    {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
        
        q.push({0,0,0,k});
        
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top[0],y=top[1];
            
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) continue;
            
            if(x==grid.size()-1 && y==grid[0].size()-1) return top[2];
            
            if(grid[x][y]==1){
                if(top[3]>0) top[3]--;
                else continue;
            }
            
            if(vis[x][y]!=-1 && vis[x][y]>=top[3]){
                continue;
            }
            vis[x][y]=top[3];
            
            q.push({x+1,y,top[2]+1,top[3]});
            q.push({x,y+1,top[2]+1,top[3]});
            q.push({x-1,y,top[2]+1,top[3]});
            q.push({x,y-1,top[2]+1,top[3]});
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        return bfs(grid,k);
    }
};