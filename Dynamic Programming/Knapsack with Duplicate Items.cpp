// problem link --> https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution
{
public:
    int helper(int idx, int n, int cap, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (idx == n)
            return 0;

        if (dp[idx][cap] != -1)
            return dp[idx][cap];
        // Take
        int take = 0;
        if (cap >= wt[idx])
            take = val[idx] + helper(idx, n, cap - wt[idx], val, wt, dp);

        int non_take = helper(idx + 1, n, cap, val, wt, dp);

        return dp[idx][cap] = max(take, non_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        return helper(0, N, W, val, wt, dp);
    }
};