// problem link --> https://practice.geeksforgeeks.org/problems/96161dfced02d544fc70c71d09b7a616fe726085/1

class Solution
{
public:
    int M = 1e9 + 7;
    int dfs(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (x == n - 1 && y == m - 1)
            return 1;
        if (dp[x][y] != -1)
            return dp[x][y];
        int ans = 0;
        if (y + 1 < m && grid[x][y + 1] == 1)
        {
            ans = (ans % M + dfs(x, y + 1, n, m, grid, dp) % M) % M;
        }

        if (x + 1 < n && grid[x + 1][y] == 1)
        {
            ans = (ans % M + dfs(x + 1, y, n, m, grid, dp) % M) % M;
        }

        return dp[x][y] = ans;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        if (grid[0][0] == 0)
            return 0;
        return dfs(0, 0, n, m, grid, dp);
    }
};