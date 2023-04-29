// problem link ---> https://leetcode.com/problems/accounts-merge/

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        Disjoint ds(n);

        map<string, int> MailToIdx;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (MailToIdx.find(accounts[i][j]) != MailToIdx.end())
                {
                    int idx = MailToIdx[accounts[i][j]];
                    ds.UnionBySize(idx, i);
                }
                else
                {
                    MailToIdx[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back({accounts[i][0]});
        }

        for (auto it : MailToIdx)
        {
            temp[ds.findUPar(it.second)].push_back(it.first);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (temp[i].size() > 1)
            {
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};