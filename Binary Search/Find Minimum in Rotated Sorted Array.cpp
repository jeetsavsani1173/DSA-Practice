// problem link --> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,ans=INT_MAX;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]<=nums[r])
            {
                r=mid-1;
                ans=min(ans,nums[mid]);
            }
            else
            {
                ans=min(ans,nums[mid]);
                l=mid+1;
            }
        }
        
        // return nums[l];
        return ans;
    }
};