// problem link --> https://leetcode.com/problems/minimum-cost-to-split-an-array/

class Solution
{
public:
    int helper(int idx, vector<int> &nums, int k, vector<int> &dp)
    {
        if (idx >= nums.size())
        {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];
        int cost = 0;
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for (int i = idx; i < nums.size(); i++)
        {
            if (mp[nums[i]] == 1)
                cost += 2;
            else if (mp[nums[i]])
                cost++;
            mp[nums[i]]++;
            ans = min(ans, cost + k + helper(i + 1, nums, k, dp));
        }
        return dp[idx] = ans;
    }
    int minCost(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size() + 1, -1);
        return helper(0, nums, k, dp);
    }
};