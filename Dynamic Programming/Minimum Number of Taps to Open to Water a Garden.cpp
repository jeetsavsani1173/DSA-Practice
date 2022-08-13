// problem link --> https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    // jump Game ll solution..
    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        if(idx==nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX-1;
        for(int jump=1;jump<=nums[idx];jump++){
            if(idx+jump<nums.size())
                ans=min(ans,helper(idx+jump,nums,dp));
        }
        return dp[idx]=ans+1;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            
            jumps[l]=max(jumps[l],r-l);
        }
        int ans=jump(jumps);
        return ans==(INT_MAX)?-1:ans;
    }
};