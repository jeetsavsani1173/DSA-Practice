// problem link --> https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution
{

    int helper(int curr, int prev, vector<int> &score, vector<vector<int>> &dp)
    {
        if (curr == score.size())
            return 0;
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int yes = (prev == -1 || score[prev] < score[curr])
                      ? score[curr] + helper(curr + 1, curr, score, dp)
                      : 0;
        int no = helper(curr + 1, prev, score, dp);

        return dp[curr][prev + 1] = max(yes, no);
    }

public:
    int maxSumIS(int arr[], int n)
    {
        vector<int> nums;
        for (int i = 0; i < n; i++)
            nums.push_back(arr[i]);
        vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
        return helper(0, -1, nums, dp);
    }
};