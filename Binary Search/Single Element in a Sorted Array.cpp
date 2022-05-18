// problem link --> https://leetcode.com/problems/single-element-in-a-sorted-array/

// first solution using XOR 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans^=nums[i];
        return ans;
    }
};

// second solution using Binary Search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int lval=(mid - 1 >= 0) ? nums[mid-1] : -1;
            int rval=(mid + 1 < nums.size()) ? nums[mid+1] : -1;
            
            if(nums[mid]!=lval && nums[mid]!=rval)
                return nums[mid];
            
            if(nums[mid]==lval)
            {
                int lCount=mid-low-1;
                if(lCount&1)
                    high=mid-2;
                else
                    low=mid+1;
            }
            else
            {
                int lCount=mid-low;
                if(lCount&1)
                    high=mid-1;
                else
                    low=mid+2;
            }
        }
        return -1;
    }
};
