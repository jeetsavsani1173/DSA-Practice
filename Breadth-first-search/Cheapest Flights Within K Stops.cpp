// problem link --> https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<vector<int>>> graph(n);
        for (auto it : flights)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        vector<int> noOfHops(n + 1, INT_MAX);
        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();

            if (noOfHops[top[1]] < top[2])
                continue;
            noOfHops[top[1]] = top[2];
            if (top[1] == dst)
                return top[0];

            if (top[2] > k)
                continue;

            for (auto it : graph[top[1]])
            {
                pq.push({top[0] + it[1], it[0], top[2] + 1});
            }
        }
        return -1;
    }
};