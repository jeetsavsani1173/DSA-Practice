// problem link --> https://leetcode.com/problems/house-robber/


// Recursion + memo
class Solution {
public:
    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        if(idx>=nums.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        // lets rob Ith house..
        int first=nums[idx]+helper(idx+2,nums,dp);
        
        // lets leave Ith house..
        int second=helper(idx+1,nums,dp);
        
        return dp[idx]=max(first,second);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return helper(0,nums,dp);
    }
};

// tabulation..
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        dp[0][n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            dp[0][i]=nums[i]+dp[1][i+1];
            dp[1][i]=max(dp[0][i+1],dp[1][i+1]);
        }
        return max(dp[0][0],dp[1][0]);
    }
};