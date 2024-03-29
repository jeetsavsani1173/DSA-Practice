// problem link -->> https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int dp[46];
    int climbStairs(int n) {
        if(n==0)
            return 1;
        else if(n<0)
            return 0;
        
        int n1,n2;
        if(n>=1 && dp[n-1]==0)
            {
                n1=climbStairs(n-1);
                dp[n-1]=n1;
            }
        else if(n>=1)
            n1=dp[n-1];
        
        if(n>=2 && dp[n-2]==0)
        {
            n2=climbStairs(n-2);
            dp[n-2]=n2;
        }
        else if(n>=2)
            n2=dp[n-2];
        
        return n1+n2;
    }
};

//second solution
class Solution {
public:
    int helper(int n,vector<int> &dp)
    {
        if(n==1 || n==2)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]=(helper(n-1,dp)+helper(n-2,dp));
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        return helper(n,dp);
    }
};