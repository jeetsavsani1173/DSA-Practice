// problem link --> https://leetcode.com/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> rmax(n,0);
        rmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            rmax[i]=max(nums[i],rmax[i+1]);
        
        int i=0,j=0;
        int ramp_ans=0;
        
        while(i<n && j<n)
        {
            if(nums[i]<=rmax[j])
            {
                ramp_ans=max(ramp_ans,j-i);
                j++;
            }else{
                i++;
            }
        }
        
        return ramp_ans;
    }
};