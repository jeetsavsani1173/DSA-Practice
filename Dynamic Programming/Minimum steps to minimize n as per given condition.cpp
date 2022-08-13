// problem link --> https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1/

// Recursion + memo

class Solution
{
public:
	int helper(int n, vector<int> &dp)
	{
		if (n == 1)
			return 0;
		if (dp[n] != -1)
			return dp[n];
		int ans = INT_MAX;
		if (n % 3 == 0)
			ans = min(ans, 1 + helper(n / 3, dp));
		if (n % 2 == 0)
			ans = min(ans, 1 + helper(n / 2, dp));
		ans = min(ans, 1 + helper(n - 1, dp));
		return dp[n] = ans;
	}
	int minSteps(int N)
	{
		vector<int> dp(N + 1, -1);
		return helper(N, dp);
	}
};

// Tabulation 

class Solution{

	public:
	
	int minSteps(int N) 
	{ 
	    vector<int> dp(N+1,INT_MAX);
	    dp[1]=dp[0]=0;
	    for(int i=2;i<=N;i++)
	    {
	        if(i%2==0) dp[i]=min(dp[i],1+dp[i/2]);
	        if(i%3==0) dp[i]=min(dp[i],1+dp[i/3]);
	        dp[i]=min(dp[i],1+dp[i-1]);
	    }
	    return dp[N];
	} 
};