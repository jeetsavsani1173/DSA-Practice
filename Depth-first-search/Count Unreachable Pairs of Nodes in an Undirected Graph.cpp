// problem link --> https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:
    void dfs(long node,vector<long long> graph[],vector<bool> &vis,long long &size)
    {
        vis[node]=true;
        size++;
        for(auto it:graph[node])
            if(!vis[it])
                dfs(it,graph,vis,size);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> graph[n+1];
        for(auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<long long> vect;
        vector<bool> vis(n+1,false);
        
        for(long long i=0;i<n;i++)
        {
            if(!vis[i])
            {
                long long size=0;
                dfs(i,graph,vis,size);
                vect.push_back(size);
            }
        }
        
        long long sum=0ll;
        for(auto &it:vect) sum+=it;
        
        long long ans=0ll;
        for(auto &it:vect)
        {
            ans+=((sum-it)*it*1ll);
        }
        return ans/2ll;
    }
};