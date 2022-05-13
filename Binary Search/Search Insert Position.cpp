// problem link -->  https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                ans=mid;
                l=mid+1;
            }
            else 
                r=mid-1;
        }
        
        return ans+1;
    }
};