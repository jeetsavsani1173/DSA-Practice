// problem link --> https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return matrix[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int mn = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (k == j)
                        continue;
                    else
                        mn = min(mn, matrix[i - 1][k]);
                }
                matrix[i][j] += mn;
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, matrix[n - 1][j]);
        return ans;
    }
};