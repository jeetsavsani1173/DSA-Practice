// problem link --> https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    long INF=-1000000000000000000;
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            long lval=(mid>0)?(nums[mid-1]):INF;
            long rval=(mid<(nums.size()-1))?(nums[mid+1]):INF;
            
            if(lval<nums[mid] && nums[mid]>rval)
                return mid;
            else if(lval<nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        
        return 0;
    }
};