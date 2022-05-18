// problem link --> https://leetcode.com/problems/critical-connections-in-a-network/

// problem of Articulation-Bridges using targen algo

class Solution {
public:
    vector<int> graph[100005];
    int timer=0;
    void dfs(int node,vector<int> &disc,vector<int> &low,int parent,vector<vector<int>> &ans)
    {
        disc[node]=low[node]=timer; // discover time
        timer++;
        
        for(auto it:graph[node])
        {
            if(disc[it]==-1)// if addjacent node is not visited
            {
                dfs(it,disc,low,node,ans);
                low[node]=min(low[node],low[it]);
                
                if(disc[node]<low[it])
                    ans.push_back({node,it});
            }
            else if(it!=parent) // for backedges
            {
                low[node]=min(low[node],disc[it]);
            }
        }
    }
    void find_bridges_using_targen(int n,vector<vector<int>> &ans)
    {
        vector<int> disc(n,-1),low(n,-1);
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
                dfs(i,disc,low,-1,ans);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        find_bridges_using_targen(n,ans);
        return ans;
    }
};