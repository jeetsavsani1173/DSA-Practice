// problem link --> https://leetcode.com/problems/number-of-provinces/

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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        Disjoint ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i < j)
                {
                    ds.UnionBySize(i + 1, j + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == ds.par[i])
                ans++;
        }
        return ans;
    }
};