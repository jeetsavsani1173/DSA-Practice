// problem link --> https://www.lintcode.com/problem/515/

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n=costs.size();
        if(n==0) return 0;
        vector<vector<int>> dp=costs;

        for(int i=1;i<costs.size();i++)
        {
            dp[i][0]+=(min(dp[i-1][1],dp[i-1][2]));
            dp[i][1]+=(min(dp[i-1][0],dp[i-1][2]));
            dp[i][2]+=(min(dp[i-1][0],dp[i-1][1]));
        }

        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};