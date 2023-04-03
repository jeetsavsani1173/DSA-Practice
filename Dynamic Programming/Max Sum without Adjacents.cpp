// problem link --> https://practice.geeksforgeeks.org/problems/7a33c749a79327b2889d420dd80342fff33aac6d/1

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        if (n == 1)
            return arr[0];
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = arr[1];
        int mx = dp[0];
        int idx = 0;

        for (int i = 2; i < n; i++)
        {
            mx = max(mx, dp[idx]);
            dp[i] = arr[i] + mx;
            idx++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};