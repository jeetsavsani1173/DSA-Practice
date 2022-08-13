// problem link --> https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    int M=1e9+7;
	    vector<vector<ll>> dp(2,vector<ll>(n+1,0));
	    dp[0][1]=dp[1][1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        dp[0][i]=(dp[0][i-1]%M+dp[1][i-1]%M)%M;
	        dp[1][i]=dp[0][i-1];
	    }
	    
	    return (dp[0][n]%M+dp[1][n]%M)%M;
	}
};