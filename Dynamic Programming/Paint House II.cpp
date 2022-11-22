// problem link --> https://www.lintcode.com/problem/516/

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int n=costs.size();
        if(n==0) return 0;
        int k=costs[0].size();
        vector<vector<int>> dp(n,vector<int>(k,0));
        dp[0]=costs[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                int mn=INT_MAX;
                for(int z=0;z<k;z++)
                {
                    if(z==j) continue;
                    else mn=min(mn,dp[i-1][z]);
                }

                dp[i][j]=costs[i][j]+mn;
            }
        }

        int ans=INT_MAX;
        for(int j=0;j<k;j++)
            ans=min(ans,dp[n-1][j]);

        return ans;
    }
};