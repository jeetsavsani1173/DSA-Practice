// probelm link --> https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<nums[r]) // right side are sorted..
            {
                if(nums[mid]<target && nums[r]>=target)// if target is present in sorted range
                    l=mid+1;
                else // otherwise
                    r=mid-1;
            }
            else if(nums[mid]>=nums[l]) // left sode are sorted
            {
                if(nums[mid]>target && nums[l]<=target)// if target is present in sorted range
                    r=mid-1;
                else // otherwise
                    l=mid+1;
            }
        }
        
        return -1;
    }
};