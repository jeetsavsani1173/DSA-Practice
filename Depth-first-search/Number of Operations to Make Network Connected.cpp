// problem link --> https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    void dfs(int node,vector<bool> &vis,vector<int> graph[])
    {
        vis[node]=true;
        for(auto it:graph[node])
            if(!vis[it])
                dfs(it,vis,graph);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> graph[n];
        for(auto it:connections)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,graph);
                count++;
            }
        }
        
        return count-1;
    }
};