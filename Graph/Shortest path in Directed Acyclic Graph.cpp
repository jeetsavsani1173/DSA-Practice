// problem link --> https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution
{
public:
    vector<pair<int, int>> graph[105];
    vector<int> shortestPath(int n, int M, vector<vector<int>> &edges)
    {
        for (auto it : edges)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int> vis(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if (vis[node] != -1)
                continue;
            vis[node] = dis;
            for (auto it : graph[node])
            {
                if (vis[it.first] == -1)
                {
                    pq.push({dis + it.second, it.first});
                }
            }
        }
        return vis;
    }
};