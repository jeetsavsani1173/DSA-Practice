// problem link --> https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        dp1[0]=1,dp2[0]=1;
        
        for(int i=1;i<n;i++)
        {
            // for UP..
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp1[i]=max(dp1[i],1+dp2[j]);
            }
            
            // for DOWN..
            for(int j=0;j<i;j++)
            {
                if(nums[j]>nums[i])
                    dp2[i]=max(dp2[i],1+dp1[j]);
            }
        }
        int ans=0;
        for(auto it:dp1) ans=max(ans,it);
        for(auto it:dp2) ans=max(ans,it);
        return ans;
    }
};