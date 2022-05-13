// problem link --> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int find_first_occu(vector<int> &nums,int target)
    {
        int l=0,r=nums.size()-1,ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]==target)
            {
                ans=mid;
                r=mid-1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
    
    int find_last_occu(vector<int> &nums,int target)
    {
        int l=0,r=nums.size()-1,ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target)
            {
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1=find_first_occu(nums,target);
        int ans2=find_last_occu(nums,target);
        
        return {ans1,ans2};
    }
};