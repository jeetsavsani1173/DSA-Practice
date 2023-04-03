// problem link --> https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &vis)
    {
        vis[node] = color;
        for (auto it : graph[node])
        {
            if (vis[it] == color)
                return false;
            if (vis[it] == -1 && !dfs(it, color ^ 1, graph, vis))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> vis(graph.size(), -1);
        bool ans = true;
        for (int i = 0; i < graph.size(); i++)
        {
            if (vis[i] == -1)
            {
                ans &= dfs(i, 0, graph, vis);
            }
        }
        return ans;
    }
};