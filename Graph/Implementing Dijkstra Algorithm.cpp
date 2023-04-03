// problem link --> https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
    vector<pair<int, int>> graph[105];

public:
    vector<int> dijkstra(int n, vector<vector<int>> graph[], int S)
    {
        vector<int> vis(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

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
                if (vis[it[0]] == -1)
                {
                    pq.push({dis + it[1], it[0]});
                }
            }
        }

        return vis;
    }
};