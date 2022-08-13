// problem link --> https://leetcode.com/problems/reachable-nodes-with-restrictions/

class Solution {
public:
    vector<int> graph[100005];
    vector<bool> vis;
    vector<bool> isres;
    int ans;
    
    void dfs(int node,bool flag)
    {
        vis[node]=true;
        if(isres[node]) flag=false;
        if(flag) ans++;
        
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it,flag);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vis=vector<bool>(n+1,false);
        isres=vector<bool>(n+1,false);
        for(auto it:restricted)
            isres[it]=true;
        
        ans=0;
        dfs(0,true);
        return ans;
    }
};