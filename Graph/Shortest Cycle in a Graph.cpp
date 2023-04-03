// problem link -- > https://leetcode.com/contest/biweekly-contest-101/problems/shortest-cycle-in-a-graph/

class Solution
{
public:
    vector<int> graph[1005];
    int shortest_cycle(int n)
    {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            vector<int> dist(n, INT_MAX);
            vector<int> par(n, -1);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int child : graph[x])
                {
                    if (dist[child] == INT_MAX)
                    {
                        dist[child] = 1 + dist[x];
                        par[child] = x;
                        q.push(child);
                    }
                    else if (par[x] != child and par[child] != x)
                        ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        for (auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        return shortest_cycle(n);
    }
};