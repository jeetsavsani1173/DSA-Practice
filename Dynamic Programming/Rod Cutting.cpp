// problem link --> https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution
{
public:
    int helper(int idx, int n, int len, int price[], vector<vector<int>> &dp)
    {
        if (idx == len || n == 0)
            return 0;

        if (dp[idx][n] != -1)
            return dp[idx][n];
        // Take
        int take = 0;
        if (n >= (idx + 1))
            take = price[idx] + helper(idx, n - (idx + 1), len, price, dp);

        // Non -Take
        int non_take = helper(idx + 1, n, len, price, dp);

        return dp[idx][n] = max(take, non_take);
    }
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, n, n, price, dp);
    }
};

// Second Solution
// Tc: O(N^2) SC:O(N^2)
class Solution
{
public:
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // Take Choice
                if (j >= i)
                    dp[i][j] = max(dp[i][j], price[i - 1] + dp[i][j - i]);
                // Non_take Choice
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        return dp[n][n];
    }
};

// Third Solution
// Tc: O(N^2) SC:O(N)
class Solution
{
public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n + 2, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= i)
                    dp[j] = max(dp[j], price[i - 1] + dp[j - i]);
            }
        }
        return dp[n];
    }
};