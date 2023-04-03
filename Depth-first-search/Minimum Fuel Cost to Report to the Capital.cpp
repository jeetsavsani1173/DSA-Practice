// problem link --> https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

class Solution
{
public:
    vector<int> graph[100005];
    long long ans = 0ll;
    long long dfs(int node, long long seats, vector<bool> &vis)
    {
        vis[node] = true;
        long long subtree_Node_Count = 1ll;
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                long long temp = dfs(it, seats, vis);
                subtree_Node_Count += temp;
                ans += (ceil((double)temp / (double)seats));
                // cout<<temp<<endl;
            }
        }

        return subtree_Node_Count;
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        for (auto it : roads)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> vis(100005);
        dfs(0, seats, vis);
        return ans;
    }
};