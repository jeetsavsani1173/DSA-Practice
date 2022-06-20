// problem link --> https://leetcode.com/problems/target-sum/

    class Solution {
public:
    int count=0;
    void helper(int idx,vector<int>&nums,int sum,int target)
    {
        if(idx==nums.size())
        {
            if(target==sum)
                count++;
            return;
        }
        // check for "+" sign
        helper(idx+1,nums,sum+nums[idx],target);
        
        // check for "-" sign
        helper(idx+1,nums,sum-nums[idx],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(0,nums,0,target);
        return count;
    }
};