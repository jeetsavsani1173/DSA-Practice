// probelm link -->  https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) {
        long M=1e9+7;
        if(n==1) return 1;
        long dp[n]; dp[0]=1; dp[1]=2;
        long dpa[n]; dpa[1]=1;
        for(int i=2;i<n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2]+2*dpa[i-1])%M;
            dpa[i]=(dp[i-2]+dpa[i-1])%M;
        }
        
        return (int)dp[n-1];
    }
};