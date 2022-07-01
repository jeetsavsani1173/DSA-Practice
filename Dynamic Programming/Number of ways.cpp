// problem link --> https://practice.geeksforgeeks.org/problems/number-of-ways2552/1

class Solution{
public:
    long long int helper(int N,vector<long long int> &dp)
    {
        if(N<0) return 0;
        if(N==0) return 1;
        if(dp[N]!=-1) return dp[N];
        return dp[N]=helper(N-1,dp)+helper(N-4,dp);
    }
    long long int arrangeTiles(int N){
        vector<long long int> dp(81,-1);
        return helper(N,dp);
    }
};