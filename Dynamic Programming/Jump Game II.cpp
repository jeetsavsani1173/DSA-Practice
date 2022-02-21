// problem link --> https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> &dp)
    {
        if(i>=(nums.size()-1))
            return dp[nums.size()-1]=0;
        if(dp[i]!=-1)
            return dp[i];
        int temp_ans=INT_MAX-2;
        for(int j=1;j<=nums[i];j++)
        {
            temp_ans=min(temp_ans,1+solve(nums,i+j,dp));
        }
        return dp[i]=temp_ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};