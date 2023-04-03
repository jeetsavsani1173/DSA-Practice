// problem link --> https://leetcode.com/problems/number-of-ways-to-earn-points/

class Solution
{
public:
    int M = 1e9 + 7;
    int helper(int idx, vector<pair<int, int>> &vpr, int target, vector<vector<int>> &dp)
    {
        // if(target<0) return 0;
        if (target == 0)
            return 1;
        if (idx == vpr.size())
            return 0;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        long long ans = 0;
        for (int times = 0; times <= vpr[idx].second; times++)
        {
            if (target >= times * vpr[idx].first)
                ans += helper(idx + 1, vpr, target - times * vpr[idx].first, dp);
        }
        return dp[idx][target] = ans % M;
    }
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int n = types.size();
        vector<pair<int, int>> vpr;
        for (auto it : types)
        {
            vpr.push_back({it[1], it[0]});
        }
        vector<vector<int>> dp(n + 5, vector<int>(target + 5, -1));
        return helper(0, vpr, target, dp);
    }
};