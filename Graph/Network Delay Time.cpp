// problem link --> https://leetcode.com/problems/network-delay-time/

class Solution
{
public:
    vector<pair<int, int>> graph[105];
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        for (auto it : times)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int> vis(n + 1, -1);
        vis[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

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

        int ans = 0;
        for (auto it : vis)
        {
            ans = max(ans, it);
            if (it == -1)
                return -1;
        }
        return ans;
    }
};