// problem link --> https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX;
        int left=0,CurrSum=0;
        
        for(int right=0;right<nums.size();right++)
        {
            CurrSum+=nums[right];
            
            while(CurrSum>=target)
            {
                minLen=min(minLen,right-left+1);
                CurrSum-=nums[left];
                left++;
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
};