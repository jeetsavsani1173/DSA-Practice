// problem link --> https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution
{
public:
    vector<pair<int, int>> graph[100005];
    int ans = 0;
    void dfs(int node, int temp)
    {
        // ans=max(ans,temp);
        for (auto it : graph[node])
        {
            dfs(it.first, temp + it.second);
            ans = max(ans, temp + it.second);
        }
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
                graph[manager[i]].push_back({i, informTime[manager[i]]});
        }
        dfs(headID, 0);
        return ans;
    }
};