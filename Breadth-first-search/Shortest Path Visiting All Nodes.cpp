// problem link --> https://leetcode.com/problems/shortest-path-visiting-all-nodes/

class Solution {
public:
    int helper(vector<vector<int>> &graph)
    {
        int n = (int)graph.size();
        // 1000 -> 1100 - > 1111 -> 10000 - 1 = 1111 its all ones
        int all = (1 << n) - 1;
        // queue<node,pair<distance,curr_mask>>
        queue<pair<int, pair<int, int>>> q;
        // set<node,curr_mask>
        set<pair<int, int>> vis;

        for (int i = 0; i < n; i++)
        {
            int mask = (1 << i);
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int val = node.first, dist = node.second.first, mask = node.second.second;
            for (auto it : graph[val])
            {
                int newMask = (mask | (1 << it)); //0001 | 0010 = 0011
                if (newMask == all)
                    return dist + 1;
                else if (vis.count({it, newMask}))
                    continue;
                vis.insert({it, newMask});
                q.push({it, {dist + 1, newMask}});
            }
        }

        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        if ((int)graph.size() == 1)
            return 0;

        return helper(graph);
    }
};