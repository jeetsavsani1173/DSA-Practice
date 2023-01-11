// problem link --> https://www.interviewbit.com/problems/subset-sum-problem/

int helper(int idx, vector<int> &nums, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (idx == nums.size())
        return 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    // Take
    if (helper(idx + 1, nums, sum - nums[idx], dp) == 1)
        return dp[idx][sum] = 1;

    // Non_Take
    if (helper(idx + 1, nums, sum, dp) == 1)
        return dp[idx][sum] = 1;

    return dp[idx][sum] = 0;
}

int Solution::solve(vector<int> &A, int B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B + 1, -1));
    return helper(0, A, B, dp);
}
