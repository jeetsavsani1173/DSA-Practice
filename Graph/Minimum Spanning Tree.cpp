// problem link --> https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> vis(V, 0);
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                if (!vis[it[0]])
                {
                    pq.push({it[1], it[0]});
                }
            }
        }

        return sum;
    }
};