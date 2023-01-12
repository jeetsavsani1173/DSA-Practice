// problem link --> https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution {
public:
    vector<int> graph[100005];
    void dfs(int node,string &s,vector<vector<int>> &dp,vector<int> &ans,vector<bool> &vis)
    {
        vis[node]=true;

        for(auto it:graph[node])
        {
            if(!vis[it])
                dfs(it,s,dp,ans,vis);
        }

        for(auto it:graph[node])
        {
            for(int j=0;j<26;j++)
            {
                dp[node][j]+=dp[it][j];
            }
        }
        dp[node][s[node]-'a']++;

        ans[node]=dp[node][s[node]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<vector<int>> dp(n,vector<int>(26,0));
        vector<int> ans(n,0);
        vector<bool> vis(n,false);
        dfs(0,labels,dp,ans,vis);
        return ans;
    }
};
