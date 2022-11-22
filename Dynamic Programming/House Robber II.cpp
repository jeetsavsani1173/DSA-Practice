// problem link --> https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int helper(int idx,int n,vector<int> &nums,vector<int> &dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        // lets rob Ith house..
        int first=nums[idx]+helper(idx+2,n,nums,dp);
        
        // lets leave Ith house..
        int second=helper(idx+1,n,nums,dp);
        
        return dp[idx]=max(first,second);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        
        return max(helper(0,n-1,nums,dp1),helper(1,n,nums,dp2));
    }
};