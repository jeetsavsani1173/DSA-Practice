// problem link --> https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution
{
public:
    vector<pair<int, int>> graph[105];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        for (auto it : redEdges)
            graph[it[0]].push_back({it[1], 0});
        for (auto it : blueEdges)
            graph[it[0]].push_back({it[1], 1});
        vector<int> ans(n, -1);
        queue<vector<int>> q;
        q.push({0, 0, -1});

        // BFS
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();

            int node = tp[0];
            int cost = tp[1];
            int color = tp[2];

            if (ans[node] == -1)
                ans[node] = cost;
            for (auto &it : graph[node])
            {
                if (color != it.second && it.first != -1)
                {
                    q.push({it.first, cost + 1, it.second});
                    it.first = -1;
                }
            }
        }

        return ans;
    }
};