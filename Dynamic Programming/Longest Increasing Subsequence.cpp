// problem link --> https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        dp[0]=1;
        
        for(int i=1;i<nums.size();i++){
            for(int k=0;k<i;k++){
                if(nums[k]<nums[i])
                    dp[i]=max(dp[i],dp[k]+1);
            }
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};