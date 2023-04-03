// problem link --> https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution
{
public:
    bool dfs(int node, vector<int> graph[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : graph[node])
        {
            if (vis[it] == 1)
                return true;
            if (vis[it] == -1)
            {
                if (dfs(it, graph, vis))
                    return true;
            }
        }
        vis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, -1);
        for (int i = 0; i < V; i++)
            if (vis[i] == -1)
                if (dfs(i, adj, vis))
                    return true;
        return false;
    }
};