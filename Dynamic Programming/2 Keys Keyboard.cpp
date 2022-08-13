// problem link --> https://leetcode.com/problems/2-keys-keyboard/

class Solution
{
public:
    long helper(long screen, long buffer, int n, vector<vector<long>> &dp)
    {
        if (screen == n)
            return 0;
        if (screen > n || buffer > n)
            return INT_MAX;
        if (dp[screen][buffer] != -1)
            return dp[screen][buffer];
        long copyPaste = 2 + helper(2 * screen, screen, n, dp);
        long paste = 1 + helper(screen + buffer, buffer, n, dp);

        return dp[screen][buffer] = min(copyPaste, paste);
    }
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<vector<long>> dp(2 * n + 1, vector<long>(2 * n + 1, -1));

        return 1ll + helper(1, 1, n, dp);
    }
};