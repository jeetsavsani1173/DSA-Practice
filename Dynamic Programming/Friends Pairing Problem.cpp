// problem link --> https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        if(n==1) return 1;
        int M=1e9+7;
        vector<long long> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]+=dp[i-1];
            dp[i]+=(dp[i-2]*(i-1));
            dp[i]%=M;
        }
            
        return dp[n];
    }
};  