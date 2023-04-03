// problem link --> https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> freq(n, 0);
        freq[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int mx = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    mx = max(mx, dp[j]);
            }

            dp[i] = max(dp[i], 1 + mx);
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && mx == dp[j])
                    freq[i] += freq[j];
            }
            if (freq[i] == 0)
                freq[i] = 1;
        }
        int mxLen = 0;
        for (int i = 0; i < n; i++)
            mxLen = max(mxLen, dp[i]);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (mxLen == dp[i])
            {
                ans += freq[i];
            }
        }
        return ans;
    }
};