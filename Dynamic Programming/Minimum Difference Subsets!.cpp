// problem link --> https://www.interviewbit.com/problems/minimum-difference-subsets/

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

int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int sum = 0;
    for (auto it : A)
        sum += it;

    int target = (sum & 1) ? (sum / 2 + 1) : (sum / 2);

    vector<vector<int>> dp(A.size() + 1, vector<int>(target + 1, -1));
    bool ans = helper(0, A, target, dp);
    if (ans)
    {
        int temp1 = target;
        int temp2 = sum - target;
        return abs(temp1 - temp2);
    }

    for (int j = target; j <= sum; j++)
    {
        if (dp[n - 1][j] == 1)
        {
            int temp1 = j;
            int temp2 = sum - j;
            return abs(temp1 - temp2);
        }
    }
    return sum;
}
