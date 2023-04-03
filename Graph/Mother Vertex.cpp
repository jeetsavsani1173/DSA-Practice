// problem link --> https://practice.geeksforgeeks.org/problems/mother-vertex/1

class Solution
{
public:
    void dfs(int node, vector<bool> &vis, vector<int> &ans, vector<int> graph[])
    {
        if (vis[node])
            return;
        vis[node] = true;
        for (auto it : graph[node])
        {
            dfs(it, vis, ans, graph);
        }
        ans.push_back(node);
    }
    void dfs2(int node, vector<bool> &vis, vector<int> graph[])
    {
        if (vis[node])
            return;
        vis[node] = true;
        for (auto it : graph[node])
        {
            dfs2(it, vis, graph);
        }
    }
    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[])
    {
        // topological sort
        vector<int> ans;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, ans, adj);
            }
        }
        reverse(ans.begin(), ans.end());

        vis = vector<bool>(V, false);
        dfs2(ans[0], vis, adj);

        for (auto it : vis)
            if (!it)
                return -1;
        return ans[0];
    }
};