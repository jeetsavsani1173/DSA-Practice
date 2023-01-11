// problem link --> https://leetcode.com/problems/target-sum/description/

class Solution
{
public:
    int helper(int idx, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if (idx == nums.size() && sum == 0)
            return 1;
        if (idx == nums.size())
            return 0;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        // Take
        int count = 0;
        if (sum >= nums[idx])
            count += helper(idx + 1, nums, sum - nums[idx], dp);

        // Non_Take
        count += helper(idx + 1, nums, sum, dp);

        return dp[idx][sum] = (count);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto it : nums)
            sum += it;
        if (sum < target)
            return 0;
        if ((sum - target) % 2 == 1)
            return 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        return helper(0, nums, (sum - target) / 2, dp);
    }
};