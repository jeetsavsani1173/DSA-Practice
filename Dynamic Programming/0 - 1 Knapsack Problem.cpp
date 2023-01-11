// problem link --> https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
public:
    int helper(int idx, int n, int wt[], int val[], int capacity, vector<vector<int>> &dp)
    {
        if (idx == n)
            return 0;

        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];

        // Take
        int Take = 0;
        if (capacity >= wt[idx])
            Take = val[idx] + helper(idx + 1, n, wt, val, capacity - wt[idx], dp);

        // Non-Take
        int NonTake = helper(idx + 1, n, wt, val, capacity, dp);

        return dp[idx][capacity] = max(Take, NonTake);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return helper(0, n, wt, val, W, dp);
    }
};

class Solution
{
public:
    // Tabulation
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                // Take
                if (j >= wt[i - 1])
                    dp[i][j] = max(dp[i][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);

                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        return dp[n][W];
    }
};