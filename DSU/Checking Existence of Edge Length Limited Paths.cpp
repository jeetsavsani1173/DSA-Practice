// problem link --> https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

class Solution
{
public:
    class DisjointSet
    {
        vector<int> rank, parent, size;

    public:
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
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[2] < b[2]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        sort(edgeList.begin(), edgeList.end(), cmp);
        DisjointSet ds(n);
        vector<bool> ans(queries.size(), false);
        vector<vector<int>> vpr;
        for (int i = 0; i < queries.size(); i++)
        {
            vpr.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }
        int idx = 0;
        sort(vpr.begin(), vpr.end(), cmp);
        for (auto it : vpr)
        {
            while (idx < edgeList.size() && edgeList[idx][2] < it[2])
            {
                ds.unionBySize(edgeList[idx][0], edgeList[idx][1]);
                idx++;
            }
            if (ds.findUPar(it[0]) == ds.findUPar(it[1]))
                ans[it[3]] = true;
        }

        return ans;
    }
};