// problem link --> https://practice.geeksforgeeks.org/problems/alien-dictionary/1

class Solution
{
public:
    vector<char> graph[26];
    string ans;
    void dfs(char ch, vector<bool> &vis)
    {
        if (vis[ch - 'a'])
            return;
        vis[ch - 'a'] = true;

        for (auto it : graph[ch - 'a'])
        {
            dfs(it, vis);
        }
        ans.push_back(ch);
    }
    string findOrder(string dict[], int N, int K)
    {
        // generating a edges of graph..
        for (int i = 0; i < N - 1; i++)
        {
            int j = i + 1;
            int idx = 0;
            while (idx < dict[i].size() && idx < dict[j].size())
            {
                if (dict[i][idx] != dict[j][idx])
                {
                    graph[dict[i][idx] - 'a'].push_back(dict[j][idx]);
                    break;
                }
                idx++;
            }
        }
        // TopoLogical Sort..
        vector<bool> vis(26, false);
        for (auto it = 'a'; it <= 'z'; it++)
            dfs(it, vis);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};