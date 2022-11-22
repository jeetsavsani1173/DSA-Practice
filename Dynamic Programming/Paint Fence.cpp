// problem link --> https://www.lintcode.com/problem/514/

// Recursion + memo
class Solution {
public:
    int helper(int n,int k,vector<int> &dp)
    {
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(helper(n-1,k,dp)+helper(n-2,k,dp))*(k-1);
    }
    int numWays(int n, int k) {
        vector<int> dp(n+1,-1);
        return helper(n,k,dp);
    }
};

// Tabulation
class Solution {
public:
    int numWays(int n, int k) {
        if(n==1) return k;
        vector<int> dp(n+1,-1);
        dp[1]=k;
        dp[2]=k*k;
        for(int i=3;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])*(k-1);
        return dp[n];
    }
};