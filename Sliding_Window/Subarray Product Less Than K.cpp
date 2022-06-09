// problem link --> https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product=1ll;
        int left=0,count=0;
        
        for(int right=0;right<nums.size();right++)
        {
            product*=(nums[right]*1ll);
            
            while(product>=k && left<=right)
            {
                product/=nums[left]*1ll;
                left++;
            }
            
            count+=(right-left+1);
        }
        return count;
    }
};