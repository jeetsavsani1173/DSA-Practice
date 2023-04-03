// problem link --> https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

class Solution
{
public:
    // static bool cmp(int &a,int &b)
    // {
    //     return a>=b;
    // }
    vector<int> graph[100005];
    int ans = 0;
    int dfs(int node, int p, vector<bool> &vis, string &s)
    {
        vis[node] = true;
        vector<int> temp;
        for (auto it : graph[node])
        {
            if (!vis[it])
                temp.push_back(dfs(it, node, vis, s));
        }
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        // cout<<node<<" -> ";
        // for(auto it:temp)
        //     cout<<it<<" ";
        // cout<<endl;
        if (temp.size() == 0)
        {
            ans = max(ans, 1);
            if (p != -1 && s[node] == s[p])
            {
                return 0;
            }
            return 1;
        }
        else if (temp.size() == 1)
        {
            ans = max(ans, 1 + temp[0]);
            if (p != -1 && s[node] == s[p])
            {
                return 0;
            }
            return 1 + temp[0];
        }
        else
        {
            ans = max(ans, 1 + temp[0] + temp[1]);
            if (p != -1 && s[node] == s[p])
            {
                return 0;
            }
            return 1 + temp[0];
        }
    }
    int longestPath(vector<int> &parent, string s)
    {
        vector<bool> vis(parent.size(), false);
        for (int i = 1; i < parent.size(); i++)
        {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        ans = 0;
        dfs(0, -1, vis, s);
        return ans;
    }
};