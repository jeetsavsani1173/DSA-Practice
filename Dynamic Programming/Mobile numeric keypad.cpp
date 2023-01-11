// problem link --> https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution
{
public:
    long long dfs(int i, int N, vector<vector<long long>> &dp)
    {
        if (N == 0)
            return 1ll;
        long long ans = 0;
        if (dp[i][N] != -1ll)
            return dp[i][N];
        if (i == 0)
            ans += (dfs(0, N - 1, dp) + dfs(8, N - 1, dp));
        if (i == 1)
            ans += (dfs(1, N - 1, dp) + dfs(2, N - 1, dp) + dfs(4, N - 1, dp));
        if (i == 2)
            ans += (dfs(2, N - 1, dp) + dfs(1, N - 1, dp) + dfs(3, N - 1, dp) + dfs(5, N - 1, dp));
        if (i == 3)
            ans += (dfs(3, N - 1, dp) + dfs(2, N - 1, dp) + dfs(6, N - 1, dp));
        if (i == 4)
            ans += (dfs(4, N - 1, dp) + dfs(1, N - 1, dp) + dfs(5, N - 1, dp) + dfs(7, N - 1, dp));
        if (i == 5)
            ans += (dfs(5, N - 1, dp) + dfs(2, N - 1, dp) + dfs(4, N - 1, dp) + dfs(6, N - 1, dp) + dfs(8, N - 1, dp));
        if (i == 6)
            ans += (dfs(6, N - 1, dp) + dfs(3, N - 1, dp) + dfs(5, N - 1, dp) + dfs(9, N - 1, dp));
        if (i == 7)
            ans += (dfs(7, N - 1, dp) + dfs(4, N - 1, dp) + dfs(8, N - 1, dp));
        if (i == 8)
            ans += (dfs(8, N - 1, dp) + dfs(5, N - 1, dp) + dfs(7, N - 1, dp) + dfs(9, N - 1, dp) + dfs(0, N - 1, dp));
        if (i == 9)
            ans += (dfs(9, N - 1, dp) + dfs(6, N - 1, dp) + dfs(8, N - 1, dp));

        return dp[i][N] = ans;
    }
    long long getCount(int N)
    {
        vector<vector<long long>> dp(10, vector<long long>(N + 1, -1ll));
        long long ans = 0ll;
        for (int i = 0; i < 10; i++)
            ans += dfs(i, N - 1, dp);
        return ans;
    }
};