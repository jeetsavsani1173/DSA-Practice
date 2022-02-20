// probelm link --> https://leetcode.com/problems/unique-paths/

// recursion + mamoization
class Solution {
public:
    int helper(int m, int n,vector<vector<int>> &dp) {
        if(n<0 || m<0)
            return 0;
        if(n==1 && m==1)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        return dp[m][n]=helper(m-1,n,dp)+helper(m,n-1,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(105,vector<int>(105,-1));
        
        return helper(m,n,dp);
    }
};

// tabulation mathod
class Solution {
public:   
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(105,vector<int>(105,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};