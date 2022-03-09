// problem link --> https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution {
public:
    int countOrders(int n) {
        vector<long long> dp(n+1,0);
        int M=pow(10,9)+7;
        dp[0]=1;
        for(long i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]*i*(2*i-1);
            dp[i]=dp[i]%M;
        }
        
        return (dp[n]);
    }
};