// problem link --> https://leetcode.com/problems/redundant-connection/

class Solution
{
public:
    class Disjoint
    {
    public:
        vector<int> par, size;
        Disjoint(int n)
        {
            par.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
                par[i] = i;
        }

        int findUPar(int n)
        {
            if (par[n] == n)
                return n;
            return par[n] = findUPar(par[n]);
        }

        void UnionBySize(int u, int v)
        {
            int pu = findUPar(u);
            int pv = findUPar(v);

            if (par[pu] == par[pv])
                return;
            if (size[pu] < size[pv])
            {
                par[pu] = pv;
                size[pv] += size[pu];
            }
            else
            {
                par[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        Disjoint ds(n);

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                ds.UnionBySize(u, v);
            }
            else
            {
                return {u, v};
            }
        }
        return {};
    }
};