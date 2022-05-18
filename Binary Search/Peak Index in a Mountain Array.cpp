// problem link --> https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int lval=(mid>0)?(nums[mid-1]):INT_MIN;
            int rval=(mid<(nums.size()-1))?(nums[mid+1]):INT_MIN;
            
            if(lval<nums[mid] && nums[mid]>rval)
                return mid;
            else if(lval<nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        
        return -1;
    }
};