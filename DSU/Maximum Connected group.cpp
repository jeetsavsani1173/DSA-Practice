// problem link --> https://practice.geeksforgeeks.org/problems/maximum-connected-group/0

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // find Ultimate Parent with path compression..
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank..
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cell = i * n + j;
                if (grid[i][j] == 0)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    if (isValid(newX, newY, n, n) && grid[newX][newY] == 1)
                    {
                        int tempCell = newX * n + newY;
                        ds.unionBySize(cell, tempCell);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                int cell = i * n + j;
                int temp_ans = 1;
                set<int> st;
                for (int k = 0; k < 4; k++)
                {
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    if (isValid(newX, newY, n, n) && grid[newX][newY] == 1)
                    {
                        int tempCell = newX * n + newY;
                        st.insert(ds.findUPar(tempCell));
                    }
                }
                for (auto it : st)
                {
                    temp_ans += ds.size[it];
                }
                ans = max(ans, temp_ans);
            }
        }
        for (int cell = 0; cell < n * n; cell++)
        {
            ans = max(ans, ds.size[ds.findUPar(cell)]);
        }
        return ans;
    }
};