// problem link --> https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1

class Solution {
  public:
    long long numberOfWays(long long N) {
        if(N==1) return 1ll;
        long long M=1e9+7;
        vector<long long> dp(N+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=N;i++)
            dp[i]=(dp[i-1]+dp[i-2])%M;
            
        return dp[N];
    }
};