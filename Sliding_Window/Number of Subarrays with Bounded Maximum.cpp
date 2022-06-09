// problem link --> https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public: // count subarray with max > x
    int helper(vector<int> &nums,int x)
    {
        long idx=-1,ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>x) idx=i;
            ans += idx+1;
        } 
        return (int)ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return helper(nums,left-1)-helper(nums,right);
    }
};