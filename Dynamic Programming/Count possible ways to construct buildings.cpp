// problem link --> https://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

class Solution{
	public:
	int TotalWays(int N)
	{
	    int M=1e9+7;
	    vector<long long> dp(N+1,0);
	    dp[1]=2;
	    dp[2]=3;
	    for(int i=3;i<=N;i++)
	        dp[i]=((dp[i-1]%M)+(dp[i-2]%M))%M;
	        
	   return ((dp[N]%M)*(dp[N]%M))%M;
	}
};