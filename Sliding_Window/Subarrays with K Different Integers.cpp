// problem link --> https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
public:
    int Count_OF_subarray_with_Atmost_K_disc_Number(vector<int> &nums,int k)
    {
        map<int,int> mp;
        int left=0,count=0;
        
        for(int right=0;right<nums.size();right++)
        {
            mp[nums[right]]++;
            
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) 
                    mp.erase(nums[left]);
                left++;
            }
            count+=(right-left+1);
        }
        
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // for atmost k distinct integers
        int first=Count_OF_subarray_with_Atmost_K_disc_Number(nums,k); 
        // for atmost k-1 distinct integers
        int second=Count_OF_subarray_with_Atmost_K_disc_Number(nums,k-1);
        
        // exact k = atmost k - atmost k-1 
        return first-second;
    }
};

