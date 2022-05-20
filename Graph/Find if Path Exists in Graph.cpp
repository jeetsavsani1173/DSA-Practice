// problem link--> https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    vector<int> graph[200005];
    void dfs(int node,vector<bool> &vis)
    {
        vis[node]=true;
        for(auto it:graph[node])
        {
            if(!vis[it])
                dfs(it,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n+1,false);
        
        dfs(source,vis);
        
        if(vis[destination])
            return true;
        else
            return false;
    }
};