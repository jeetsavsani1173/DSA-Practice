// problem link --> https://leetcode.com/problems/possible-bipartition/description/

class Solution
{
public:
    vector<int> graph[2005];

    bool dfs(int node, int c, vector<int> &color)
    {
        color[node] = c;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (dfs(it, c ^ 1, color) == false)
                    return false;
            }
            else if (color[it] == c)
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        for (auto it : dislikes)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color) == false)
                    return false;
            }
        }
        return true;
    }
};