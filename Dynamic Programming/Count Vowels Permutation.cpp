// problem link --> https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    int countVowelPermutation(int n) {
        int M=1e9+7;
        vector<vector<int>> dp(5,vector<int>(n+1,1));
        
        for(int i=2;i<=n;i++)
        {
            dp[0][i]=((dp[1][i-1]+dp[2][i-1])%M+dp[4][i-1])%M;
            dp[1][i]=(dp[0][i-1]+dp[2][i-1])%M;
            dp[2][i]=(dp[1][i-1]+dp[3][i-1])%M;
            dp[3][i]=dp[2][i-1];
            dp[4][i]=(dp[2][i-1]+dp[3][i-1])%M;
        }
        int ans=0;
        for(int i=0;i<5;i++)
            ans=(ans+dp[i][n])%M;
        return ans;
    }
};