// problem link --> https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    vector<int> graph[205];
    void dfs(int node,vector<bool> &vis)
    {
        vis[node]=true;
        
        for(auto it:graph[node])
        {
            if(!vis[it])
                dfs(it,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    graph[i+1].push_back(j+1);
                }
            }
        }
        
        int cnt=0;
        vector<bool> vis(205,false);
        
        for(int i=1;i<=isConnected.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,vis);
                cnt++;
            }
        }
        return cnt;
    }
};