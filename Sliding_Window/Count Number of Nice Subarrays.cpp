// problem link --> https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int countOfSubarraysAtMostkOddNumber(vector<int> &nums,int k)
    {
        int left=0,count=0,ans=0;
        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]&1) count++;
            
            while(count>k){
                if(nums[left]&1) count--;
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int first=countOfSubarraysAtMostkOddNumber(nums,k);
        int second=countOfSubarraysAtMostkOddNumber(nums,k-1);
        // cout<<first<<" "<<second<<endl;
        return first-second;
    }
};