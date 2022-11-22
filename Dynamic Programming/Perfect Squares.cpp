// problem link --> https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int helper(int idx,vector<int> &nums,int n,vector<vector<int>> &dp)
    {
        if(n==0) return 0;
        if(idx==nums.size()) return INT_MAX-2;
        
        if(dp[idx][n]!=-1) return dp[idx][n];
        int temp=INT_MAX-2;
        // Take
        if(nums[idx]<=n)
            temp=1+helper(idx,nums,n-nums[idx],dp);
        
        // Non-Take
        temp=min(temp,helper(idx+1,nums,n,dp));
        
        return dp[idx][n]=temp;
    }
    int numSquares(int n) {
        vector<int> nums;
        for(int i=1;i<=100;i++)
            nums.push_back(i*i);
        vector<vector<int>> dp(nums.size()+1,vector<int>(n+1,-1));
        return helper(0,nums,n,dp);
    }
};