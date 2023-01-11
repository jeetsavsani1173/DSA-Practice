// problem link --> https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i - 1) >= 0 && (j - 1) >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                if ((i - 1) >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if ((i - 1) >= 0 && (j + 1) < m)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);

                dp[i][j] += matrix[i][j];
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
            ans = min(ans, dp[n - 1][j]);

        // for(auto it:dp)
        // {
        //     for(auto it1:it)
        //         cout<<it1<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};