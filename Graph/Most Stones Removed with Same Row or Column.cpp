// problem link --> https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    vector<int> graph[1005];
    
    void dfs(int node,int &size,vector<bool> &vis)
    {
        vis[node]=true;
        size++;
        for(auto it:graph[node])
        {
            if(!vis[it])
                dfs(it,size,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
        
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<i<<" -> ";
        //     for(auto it:graph[i])
        //         cout<<it<<" ";
        //     cout<<endl;
        // }
        
        int ans=0;
        vector<bool> vis(n+1,false);
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int size=0;
                dfs(i,size,vis);
                
                ans+=(size-1);
            }
        }
        
        return ans;
    }
};