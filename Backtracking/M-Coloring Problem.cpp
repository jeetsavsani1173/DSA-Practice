problem link-- > https : // practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

                         class Solution
{
public:
    bool canColor(int src, bool graph[101][101], int NewColor, vector<int> &vis)
    {
        for (int nbr = 0; nbr < vis.size(); nbr++)
        {
            if (graph[src][nbr] && vis[nbr] == NewColor)
                return false;
        }
        return true;
    }
    bool helper(int idx, bool graph[101][101], int color, vector<int> &vis)
    {
        if (idx == vis.size())
            return true;

        for (int c = 0; c < color; c++)
        {
            if (canColor(idx, graph, c, vis))
            {
                vis[idx] = c;
                if (helper(idx + 1, graph, color, vis))
                    return true;
                vis[idx] = -1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> vis(n, -1);
        return helper(0, graph, m, vis);
    }
};