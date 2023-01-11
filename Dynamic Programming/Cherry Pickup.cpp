// problem link --> https://leetcode.com/problems/cherry-pickup/

class Solution
{
public:
    int dp[51][51][51];
    // r1+c1=r2+c2 will always hold so we can reduce 4 state to 3 state..
    int helper(int r1, int c1, int r2, int c2, vector<vector<int>> &grid)
    {
        // nagetive basecase
        if (r1 >= grid.size() || c1 >= grid.size() || grid[r1][c1] == -1 || r2 >= grid.size() || c2 >= grid.size() || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }

        // positive basecase
        if (r1 == grid.size() - 1 && c1 == grid.size() - 1)
        { // both will reach to last cell at a same time
            return grid[r1][c1];
        }

        int ans = grid[r1][c1] + grid[r2][c2];
        if (r1 == r2 && c1 == c2)
            ans -= grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int DD = helper(r1 + 1, c1, r2 + 1, c2, grid);
        int DR = helper(r1 + 1, c1, r2, c2 + 1, grid);
        int RD = helper(r1, c1 + 1, r2 + 1, c2, grid);
        int RR = helper(r1, c1 + 1, r2, c2 + 1, grid);

        return dp[r1][c1][r2] = ans + max(max(DD, DR), max(RD, RR));
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        for (int i = 0; i < 51; i++)
            for (int j = 0; j < 51; j++)
                for (int k = 0; k < 51; k++)
                    dp[i][j][k] = -1;
        int ans = helper(0, 0, 0, 0, grid);
        if (ans <= 0)
            return 0;
        else
            return ans;
    }
};