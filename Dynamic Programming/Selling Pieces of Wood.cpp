// problem link --> https://leetcode.com/problems/selling-pieces-of-wood/

class Solution {
public:
    long long helper(int m,int n,map<pair<long long,long long>,long long> &mp,vector<vector<long long>> &dp)
    {
        if(m==0 || n==0) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        long long ans=mp[{m,n}];
        
        // for horizonatal Cut..
        for(int i=1;i<=m/2;i++)
            ans=max(ans,helper(i,n,mp,dp)+helper(m-i,n,mp,dp));
        
        // for veritical Cut..
        for(int j=1;j<=n/2;j++)
            ans=max(ans,helper(m,j,mp,dp)+helper(m,n-j,mp,dp));
        
        return dp[m][n]=ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pair<long long,long long>,long long> mp;
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
        for(auto it:prices) mp[{it[0],it[1]}]=it[2];
        
        return helper(m,n,mp,dp);
    }
};