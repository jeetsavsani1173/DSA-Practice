// problem link --> https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        queue<pair<pair<int,int>,int>> Q;
        Q.push({{0,0},1});
        grid[0][0]=1;
        while(!Q.empty())
        {
            auto it=Q.front().first;
            int d=Q.front().second;
            Q.pop();
            
            if(it.first==n-1 && it.second==n-1)
                return d;
            
            for(int i=0;i<8;i++)
            {
                int newx=it.first+dx[i];
                int newy=it.second+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==0)
                {
                    grid[newx][newy]=1;
                    Q.push({{newx,newy},d+1});
                }
                
                // if(newx==n-1 && newy==n-1)
                //     return d+1;
            }
        }
        
        return -1;
    }
};