// problem link --> https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1

class Solution{
	public:
	int M;
	int helper(int n,int m,vector<int> &dp)
	{
	    if(dp[n]!=-1) return dp[n];
	    if(n==m) return 2;
	    if(n<m) return 1;
	    // for vertical
	    int ans=helper(n-1,m,dp);
	    
	    // for horizontal
	    ans=((ans%M)+(helper(n-m,m,dp)%M))%M;
	    
	    return dp[n]=ans;
	}
	int countWays(int n, int m)
	{
	    M=1e9+7;
	    vector<int> dp(n+1,-1);
	    return helper(n,m,dp);
	}
};