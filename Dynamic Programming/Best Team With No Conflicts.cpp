// problem link --> https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution
{
public:
    int helper(int curr, int prev, vector<int> &score, vector<vector<int>> &dp)
    {
        if (curr == score.size())
            return 0;
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int yes = (prev == -1 || score[prev] <= score[curr])
                      ? score[curr] + helper(curr + 1, curr, score, dp)
                      : 0;
        int no = helper(curr + 1, prev, score, dp);

        return dp[curr][prev + 1] = max(yes, no);
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = ages.size();
        vector<pair<int, int>> vpr;
        for (int i = 0; i < n; i++)
            vpr.push_back({ages[i], scores[i]});
        sort(vpr.begin(), vpr.end());

        for (int i = 0; i < n; i++)
            scores[i] = vpr[i].second;
        vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
        return helper(0, -1, scores, dp);
    }
};