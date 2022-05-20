// problem link -->>https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkforcycleDFS(int node,int par,vector<int> adj[],vector<int> &vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(checkforcycleDFS(it,node,adj,vis))
                    return true;
            }
            else if(it!=par)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkforcycleDFS(i,-1,adj,vis))
                     return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driv