// problem link --> https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

class Solution
{
public:
    vector<int> graph[100005];
    int dfs(int node, vector<bool> &hasApple, vector<bool> &vis, vector<int> &dp)
    {
        vis[node] = true;
        int ans = (hasApple[node] == true) ? 1 : 0;
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                ans += dfs(it, hasApple, vis, dp);
            }
        }
        return dp[node] = ans;
    }
    int ans = 0;
    void dfs2(int node, vector<bool> &vis, vector<int> &dp)
    {
        vis[node] = true;
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                if (dp[it] > 0)
                {
                    ans++;
                    dfs2(it, vis, dp);
                    ans++;
                }
            }
        }
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        for (auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        // Pre-Processing
        vector<int> dp(n + 1, 0);
        vector<bool> vis(n + 1, false);
        dfs(0, hasApple, vis, dp);

        // for(auto it:dp)
        //     cout<<it<<" ";
        vector<bool> vis1(n + 1, false);
        dfs2(0, vis1, dp);
        return ans;
    }
};