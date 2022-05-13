// problem link -->  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:// Tc -> O(logn) in avg case O(n) in worst case.. when all element of array are equal then we need go for linear search...
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,ans=INT_MAX;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]<nums[r])
            {
                r=mid;
                ans=min(ans,nums[mid]);
            }
            else if(nums[mid]>nums[r])
            {
                ans=min(ans,nums[mid]);
                l=mid+1;
            }
            else
                r--; // if both side are sorted then reduce search space by 1..
        }
        return nums[l];
    }
};