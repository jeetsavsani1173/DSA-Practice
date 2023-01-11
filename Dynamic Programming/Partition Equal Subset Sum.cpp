// problem link --> https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution
{
public:
    bool helper(int idx, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1;
        if (idx == nums.size())
            return 0;
        if (sum < 0)
            return false;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        // Take
        if (helper(idx + 1, nums, sum - nums[idx], dp) == true)
            return dp[idx][sum] = true;

        // Non_Take
        if (helper(idx + 1, nums, sum, dp) == true)
            return dp[idx][sum] = true;

        return dp[idx][sum] = false;
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto it : nums)
            sum += it;
        if (sum & 1)
            return false;
        sum /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        return helper(0, nums, sum, dp);
    }
};